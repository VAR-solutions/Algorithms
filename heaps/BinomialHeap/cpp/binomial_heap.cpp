#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

template <typename T>
class BinomialHeap
{
    /**
     * @brief Node in the binomial heap
     *  - is as a Node in a forest of binary heaps (which are implemeted as a tree)
     *  - holds a value of type T
     *  - keeps a degree metadata, which is the number of children in the forest
     *  - keeps track of its next neighbor in the forest via `*sibling`
     *  - keeps track of its parent in the tree via `*parent`
     */
    struct Node
    {
        T value;
        int degree;
        Node *child, *sibling;

        Node() : degree(0), child(nullptr), sibling(nullptr) {}

        Node(const T &value) : value(value), degree(0), child(nullptr), sibling(nullptr) {}

    } * root;

    /**
     * @brief Recursively clean up all nodes in the Binomial Heap
     * - travers all children nodes, before travelling through all neighbors
     *
     * @param ptr
     */
    void destruct(Node *ptr)
    {
        if (!ptr)
            return;
        destruct(ptr->child);
        destruct(ptr->sibling);
        delete ptr;
    }

    /**
     * @brief Links two nodes in the forest
     *
     * @param a : Node 1
     * @param b : Node 2
     * @return Node*
     */
    Node *link(Node *a, Node *b)
    {
        assert(a->degree == b->degree);
        if (a->value <= b->value)
        {
            ++a->degree;
            if (!a->child)
            {
                a->child = b;
            }
            else
            {
                Node *ptr = a->child;
                while (ptr->sibling)
                    ptr = ptr->sibling;
                ptr->sibling = b;
            }
            return a;
        }
        else
        {
            // want to "reverse" the nodes being linked, so we get the correct min value
            return link(b, a);
        }
    }

    /**
     * @brief Insertion helper for inserting a node into the forest
     *
     * @param child : Node where the insertion happens
     * @param sibling : Node to be inserted
     * @return root of the inserted forest.
     */
    Node *insert(Node *child, Node *sibling)
    {
        if (!sibling)
            return child;
        if (child->degree == sibling->degree)
        {
            Node *s_sibling = sibling->sibling;
            sibling->sibling = nullptr;
            return insert(link(child, sibling), s_sibling);
        }
        else
        {
            child->sibling = sibling;
            return child;
        }
    }

    /**
     * @brief Merges two trees (binary heaps) in the forest
     *  - this happens when we have too many or too few nodes for a single tree
     *
     * @param a : Root of the first (sub) tree
     * @param b : Root of the second (sub) tree
     * @return Root of the merged tree
     */
    Node *merge(Node *a, Node *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;

        if (a->degree < b->degree)
        {
            a->sibling = merge(a->sibling, b);
            return a;
        }
        else if (a->degree > b->degree)
        {
            b->sibling = merge(a, b->sibling);
            return b;
        }
        else
        {
            Node *sibling = merge(a->sibling, b->sibling);
            a->sibling = b->sibling = nullptr;
            Node *c = link(a, b);
            return insert(c, sibling);
        }
    }

    /**
     * @brief Find the top of the heap, by traversing all root nodes in the forest
     * - Assigns the two pointers passed to it,
     *   - `_min_cur` to the Node that contains the extremum
     *   - `_min_prev` the node that contains the next extremum
     * @param _min_cur : pointer to be assigned the extremum node
     * @param _min_prev : pointer to be assigned the next extremum node
     */

    void find_top(Node *&_min_prev, Node *&_min_cur)
    {
        Node *prev = nullptr, *cur = root;
        Node *min_prev = nullptr, *min_cur = root;
        while (cur)
        {
            if (cur->value < min_cur->value)
            {
                min_cur = cur;
                min_prev = prev;
            }
            prev = cur;
            cur = cur->sibling;
        }
        _min_prev = min_prev;
        _min_cur = min_cur;
    }

public:
    /**
     * @brief Default constructor for a new BinomialHeap
     *
     */
    BinomialHeap() : root(nullptr) {}

    /**
     * @brief Destructor for the heap, free only
     * the nodes it currently owns.
     * The nodes popped during its lifetime are destroyed when they
     * leave the tree
     *
     */
    ~BinomialHeap()
    {
        destruct(root);
    }

    /**
     * @brief Enqueue method for the heap
     *
     * @param x : the value to insert
     */
    void push(const T &x)
    {
        Node *ptr = new Node(x);
        root = merge(root, ptr);
    }

    /**
     * @brief Dequeue method for the heap
     *
     * @return T : the top (extremum) value
     */
    T pop()
    {
        Node *min_prev, *min_cur;
        find_top(min_prev, min_cur);
        T value = min_cur->value;
        if (min_prev)
            min_prev->sibling = min_cur->sibling;
        else
        {
            root = min_cur->sibling;
        }
        root = merge(min_cur->child, root);
        delete min_cur;
        return value;
    }

    /**
     * @brief Peek the top of the heap
     *
     * @return const T& : reference to the top of the queue
     */
    const T &top()
    {
        Node *min_prev = nullptr, *min_cur = root;
        find_top(min_prev, min_cur);
        return min_cur->value;
    }
};

// tests / usage
int main()
{
    cout << "Hello. Binomial heap!" << endl;

    BinomialHeap<int> binomial_heap;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int T = 0; T < 100; T++)
    {
        for (int i = 0; i < 100000; i++)
        {
            int data = rand() % 10000;
            binomial_heap.push(data);
            pq.push(data);
        }

        for (int i = 0; i < 100000; i++)
        {
            assert(pq.top() == binomial_heap.top()); // maintain sorted priority queue order
            pq.pop();
            binomial_heap.pop();
        }
    }
    return 0;
}