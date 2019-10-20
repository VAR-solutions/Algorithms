#include <iostream>

class Node {
    friend class SinglyLinkedList;

private:
    int data;
    Node *next;
};

class SinglyLinkedList {
private:
    Node *head;

    int getSize() {
        int size{};
        Node *h = head;

        while (h) {
            h = h->next;
            size++;
        }

        return size;
    }

public:
    SinglyLinkedList() : head{nullptr} {}

    void insert(int index, int data) {
        if (index < 0 || index > SinglyLinkedList::getSize()) {
            std::cout << "Invalid index" << std::endl;
            return;
        }

        Node *h = head;
        Node *t = new Node;
        t->next = nullptr;
        t->data = data;

        if (index == 0) {
            t->next = head;
            head = t;
            return;
        }

        for (int i{}; i < index - 1; ++i)
            h = h->next;

        t->next = h->next;
        h->next = t;
    }

    void append(int data) {
        insert(getSize(), data);
    }

    void remove(int index) {
        if (index < 0 || index > SinglyLinkedList::getSize() - 1) {
            std::cout << "Invalid index" << std::endl;
            return;
        }

        Node *h = head;

        if (index == 0) {
            head = head->next;
            delete h;
            return;
        }

        for (int i{}; i < index - 1; ++i)
            h = h->next;

        Node *t = h->next;
        h->next = h->next->next;
        delete t;
    }

    void display() {
        Node *h = head;
        while (h) {
            std::cout << h->data << ", ";
            h = h->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList ll;
    ll.append(1);
    ll.display(); // 1,
    ll.append(3);
    ll.display(); // 1, 3,
    ll.insert(1, 2);
    ll.append(4);
    ll.append(5);
    ll.display(); // 1, 2, 3, 4, 5,
    ll.insert(-1, 0); // invalid index
    ll.insert(6, 12); // invalid index
    ll.remove(0);
    ll.display(); // 2, 3, 4, 5,
    ll.insert(4, 6);
    ll.display(); // 2, 3, 4, 5, 6
    ll.remove(5); // invalid index
    ll.remove(4);
    ll.display(); // 2, 3, 4, 5
    return 0;
}