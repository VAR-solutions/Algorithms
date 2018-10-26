using System;

namespace Collections {

    public class Node<T> {
        internal T Data { get; set; }
        internal Node<T> Successor { get; set; }

        internal Node (T data) {
            Data = data;
        }
    }

    public class LinkedList<T> {
        private Node<T> Head { get; set; }

        public T this [int index] {
            get {
                int i = 0;
                Node<T> current = Head;

                if (current == null) {
                    throw new IndexOutOfRangeException ();
                }

                while (i < index) {
                    if (current.Successor == null) {
                        throw new IndexOutOfRangeException ();
                    }
                    current = current.Successor;
                    i++;
                }

                return current.Data;
            }
        }
        public void Append (T data) {
            Node<T> newNode = new Node<T> (data);
            if (Head == null) {
                Head = newNode;
            } else {
                Node<T> current = Head;
                while (current.Successor != null) {
                    current = current.Successor;
                }
                current.Successor = newNode;
            }
        }
    }
}