/**
 * About Heaps: In computer science, a heap is a specialized tree-based data structure
 * that satisfies the heap property: if P is a parent node of C, then the key (the value)
 *  of P is either greater than or equal to (in a max heap) or less than or equal to
 * (in a min heap) the key of C. The node at the "top" of the heap (with no parents)
 *  is called the root node.
 * The heap is one maximally efficient implementation of an abstract data type called
 * a priority queue, and in fact priority queues are often referred to as "heaps",
 * regardless of how they may be implemented. A common implementation of a heap is the
 * binary heap, in which the tree is a binary tree (see figure). The heap data structure,
 * specifically the binary heap, was introduced by J. W. J. Williams in 1964, as a data
 * structure for the heapsort sorting algorithm. Heaps are also crucial in several
 * efficient graph algorithms such as Dijkstra's algorithm. 
 * (https://en.wikipedia.org/wiki/Heap_(data_structure))
 *
 * This is a Minimal Heap, so the first element will always be the smallest value.
 * The size is fixed and must be assigned when the constructor is called.
 * Here, for implementation porpuses, the first element of the heap vector is an empty
 * root. It was used didatically, because the index calculation math gets more simple
 * if the starting index of the vector is 1.
 * @author Pitágoras Alves
 */
public class Heap {

    public static void main(String[] args) {
        int[] arr = new int[] {2, 3, 0, 4, -1, 34, 10, 12, 6, -10};
        Heap heap = new Heap(arr.length);

        System.out.println("Initial vector: ");
        for(int element: arr) {
            System.out.println(element);
            heap.insert(element);
        }

        System.out.println("Heap sorted vector: ");
        while(heap.actualSize != 0){
            System.out.println(heap.getMin());
            heap.removeMin();
        }
    }

    private int actualSize, maxSize;
    private int[] nodes;

    /**
     * Creates an empty heap data structure with a fixed size
     * @param size
     */
    public Heap(int size){
        nodes = new int[size+1];
        maxSize = size;
        actualSize = 0;
    }

    /**
     * Returns the minimal element of the heap
     * @return Minimal element value
     */
    public int getMin(){
        return nodes[1];
    }

    /**
     * Use to calculate the index of the parent of an element
     * @param i Element index
     * @return Element parent index
     */
    private int parent(int i){
        if(i == 1){
            return 0;
        }else{
            return i/2;
        }
    }

    /**
     * Use to calculate the index of the left child of an element
     * @param i Element index
     * @return  If left child exists, returns it's index. If it does not, returns 0
     */
    private int leftChild(int i){
        int n = 2*i;
        if(n <= actualSize){
            return n;
        }else{
            return 0;
        }
    }

    /**
     * Use to calculate the index of the right child of an element
     * @param i Element index
     * @return  If right child exists, returns it's index. If it does not, returns 0
     */
    private int rightChild(int i){
        int n = (2*i) + 1;
        if(n <= actualSize){
            return n;
        }else{
            return 0;
        }
    }

    /**
     * Rises a heap element
     * @param i Element index
     */
    private void rise(int i){
        if(i == 1){
            return;
        }else{
            if((nodes[parent(i)] > nodes[i]) || (nodes[parent(i)] == 0)){
                int aux = nodes[parent(i)];
                nodes[parent(i)] = nodes[i];
                nodes[i] = aux;
                rise(parent(i));
            }
        }
    }

    /**
     * Descends a heap element
     * @param i Element index
     */
    private void descend(int i){
        if(i >= actualSize || i == 0){
            return;
        }else{
            //System.out.println("Descend" + i);
            int child = 0;
            //Decide what child node has the smallest value
            if(rightChild(i) != 0){
                if(leftChild(i) != 0){
                    if(nodes[rightChild(i)] < nodes[leftChild(i)]){
                        child = rightChild(i);
                    }else{
                        child = leftChild(i);
                    }
                }else{
                    child = rightChild(i);
                }
            }else if (leftChild(i) != 0){
                child = leftChild(i);
            }
            //If there's a child node, try to switch node positions
            if(child > 0){
                if(nodes[child] < nodes[i]){
                    int aux = nodes[i];
                    nodes[i] = nodes[child];
                    nodes[child] = aux;
                    descend(child);
                }
            }
        }
    }

    /**
     * Insert new element. If the Heap is full, nothing is inserted
     * @param key Value to be inserted
     */
    public void insert(int value){
        if(actualSize < maxSize){
            actualSize++;
            nodes[actualSize] = value;
            rise(actualSize);
        }
    }

    /**
     * Removes the heap's minimal element, decreasing the total size of the data structure.
     */
    public void removeMin(){
        if(actualSize > 0){
            nodes[1] = nodes[actualSize];
            actualSize--;
            descend(1);
        }
    }
}