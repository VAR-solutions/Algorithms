/**
    This class is used to print N natural number without using any loops or conditions
    We use recursion logic to print N numbers using a generic function
 */
public class PrintNumbersWithoutLoops {
    
    public static void main(String[] args) {
        int n = 100; // the number of natural numbers to be printed
    }

    public void printNumber(int givenNumber) {
        if(givenNumber < N) {
            System.out.println(givenNumber);
            printNumber(++givenNumber);
        } else {
            return;
        }
    }

}