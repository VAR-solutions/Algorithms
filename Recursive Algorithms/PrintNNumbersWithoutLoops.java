/**
    This class is used to print N natural number without using any loops or conditions
    We use recursion logic to print N numbers using a generic function
 */
public class PrintNumbersWithoutLoops {
    public int N;
    public static void main(String[] args) {
        N = 100; // the number of natural numbers to be printed
        printNumbers(1); // prints N natural numbers starting from 1
    }

    public void printNumbers(int givenNumber) {
        if(givenNumber < N) {
            System.out.println(givenNumber);
            printNumber(++givenNumber);
        } else {
            return;
        }
    }

}