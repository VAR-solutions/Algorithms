public class heap_sort {

    static void run_heap_sort(int[] a) {
        HeapMin heap = new HeapMin(a.length);
        for(int i = 0; i < a.length; i++){
            heap.insert(a[i]);
        }
        for(int i = 0; i < a.length; i++){
            a[i] = heap.getMin();
            heap.removeMin();
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[] {2, 3, 0, 4, -1, 34, 10, 12, 6, -10};
        run_heap_sort(arr);
        for(int element: arr) {
            System.out.println(element);
        }
    }

    private static class HeapMin {
        private int actualSize, maxSize;
        private int[] nodes;

        /**
         * Creates an empty heap data structure with a fixed size
         * @param size
         */
        public HeapMin(int size){
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
        public void insert(int key){
            if(actualSize < maxSize){
                actualSize++;
                nodes[actualSize] = key;
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
}
