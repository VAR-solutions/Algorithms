public class arrayHeap<T extends Comparable> {

    private T[] heap;
    public static final int DEF_SIZE = 1024; // Set a default size for the heap
    public static int ROOT = 1;
    public int tailIndex;

    /**
     * Default Constructor
     *
     * Sets the heap array to the DEF_SIZE of 1024 and the tailIndex
     * to start at 0, which is where the first value will be placed.
     */
    public arrayHeap() {
        heap = (T[])(new Comparable[DEF_SIZE]);
        tailIndex = 0;
    }

    /**
     * Parameterized Constructor
     *
     * Sets the heap array to a user defined size and the tailIndex
     * to 0, which is where the first value will be placed.
     */
    public arrayHeap(int size) {
        if (size <= 0)
            return;
        heap = (T[])(new Comparable[size]);
        tailIndex = 0;
    }

    /**
     * Inserts a new instance of T data.
     * The data will be added to the bottom of the heap and climbs up
     * the heap until it's on top of a greater value and below a lesser
     * value.
     */
    public void insert(T data) {
        if (tailIndex >= heap.length)
            return;
        heap[tailIndex] = data;
        this.climbUp(); // climb up the heap
        tailIndex++;
    }
    /**
     * Helper method for insert() which moves the data up the heap
     */
    private void climbUp() {
        int tempIndex = this.tailIndex;
        while (tempIndex > 0 && heap[(tempIndex)].compareTo(heap[(tempIndex-1)/2]) < 0) {
            // swap
            T temp = heap[(tempIndex-1)/2];
            heap[(tempIndex-1)/2] = heap[tempIndex];
            heap[tempIndex] = temp;
            tempIndex = (tempIndex-1)/2;
        }
    }

    /**
     * Removes the data from the top of the heap, and then it replaces the top of
     * the heap with the last data element in the heap.  It will then climb down
     * until it is below a lesser value and above a greater value.
     */
    public T remove() {
        T retVal = heap[0];
        heap[0] = heap[tailIndex-1]; // set root to last element
        heap[tailIndex-1] = null;
        tailIndex--;
        this.climbDown(); // climb down
        return retVal;
    }
    /**
     * Helper method for remove() which climbs down the heap to place a piece of data.
     */
    private void climbDown() {
        int tempIndex = 0;
        while (tempIndex*2+1 < tailIndex) {
            // Find smaller child
            int smallIndex = tempIndex*2+1; // Assume left child is smaller
            if (tempIndex*2+2 < tailIndex && heap[tempIndex*2+1].compareTo(heap[tempIndex*2+2]) > 0) {
                // There is a right child, and it is smaller.
                smallIndex = tempIndex*2+2;
            }
            // Compare child to the parent
            if (heap[smallIndex].compareTo(heap[tempIndex]) < 0) {
                // swap
                T temp = heap[tempIndex];
                heap[tempIndex] = heap[smallIndex];
                heap[smallIndex] = temp;
            } else
                break;
            tempIndex = smallIndex;
        }
    }

    /**
     * Prints the heap in Breadth-order
     */
    public void printBreadth() {
        for (T val : heap) {
            if (val != null)
                System.out.println(val);
        }
    }

    /**
     * Prints the heap in In-order
     *
     * CAUTION: This method of printing deletes the entire heap
     */
    public void printInOrder() {
        for (int i = tailIndex; i > 0; i--) {
            System.out.println(this.remove());
        }
    }

    public static void main(String[] args) {
        System.out.println("I'm inside the main function!");
        arrayHeap<Integer> heap = new arrayHeap<Integer>();
        // Inserting in the heap
        heap.insert(1);
        heap.insert(24);
        heap.insert(32);
        heap.insert(14);
        heap.insert(58);
        heap.insert(6);
        heap.insert(74);
        heap.insert(18);
        heap.insert(9);
        heap.insert(100);

        heap.printBreadth();
        System.out.println("");
        heap.printInOrder();
    }
}
