import java.util.Scanner;

public class NumberGame {
   public static void main(String[] args) throws java.lang.Exception {
      System.out.println("I have randomly choosen a number between [1,100]\nTry to guess it :)");
      int randomNumber = (int) (Math.random() * 100 + 1);
      boolean hasWon = false;
      Scanner scanner = new Scanner(System.in);
      for (int chances = 7; chances > 0; chances--) {
            System.out.println("You have " + chances + " guess(es) left, Choose wisely");
         int guess = scanner.nextInt();

         if (randomNumber > guess) {

            System.out.println("Random number is greater than " + guess);
         }
         if (randomNumber < guess) {

            System.out.println("Random number is smaller than " + guess);
         }
         if (randomNumber == guess) {
            hasWon = true;
            break;
         }
      }
      if (hasWon == true) {
         System.out.println("Congrats! " + randomNumber + " is correct answer");
      } else {
         System.out.println("Sorry the Game is Over\nThe correct answer is " + randomNumber);
      }
   }
}