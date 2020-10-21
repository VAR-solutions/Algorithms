/*Tic Tac Toe(also known as Noughts and crosses or Xs and Os) is a paper and pencil game for
two players, X and O, who take turns making the spaces in a 3X3 grid.The player who
suceeds in placing three of their marks in a horizontal,vertical or diagonal row
wins the game
Note:-Save the file with MyApp.java otherwise it will give error.
*/
import java.util.Scanner;
public class MyApp {
     public static void main(String[] args) {
         	aniket();
     }
      public static void aniket(){
          Scanner scanner=new Scanner(System.in);
          char[] alpha={' ',' ',' ',' ', ' ',' ',' ',' ',' '};
        char turn='X';
        int input;
        while(true) {
            do {
                  System.out.print("enter position:");
                 input = scanner.nextInt();
            }while(alpha[input-1]=='X'||alpha[input-1]=='O');
            alpha[input - 1] = turn;
            System.out.println(" " + alpha[6] + " | " + alpha[7] + " | " + alpha[8] + " ");
            System.out.println("---+---+-----");
            System.out.println(" " + alpha[3] + " | " + alpha[4] + " | " + alpha[5] + " ");
            System.out.println("---+---+-----");
            System.out.println(" " + alpha[0] + " | " + alpha[1] + " | " + alpha[2] + " ");
            if(alpha[0]==turn && alpha[1]==turn && alpha[2]==turn||alpha[1]==turn && alpha[4]==turn && alpha[7]==turn||
                    alpha[0]==turn && alpha[3]==turn && alpha[6]==turn||alpha[0]==turn && alpha[4]==turn && alpha[8]==turn||
                    alpha[2]==turn && alpha[5]==turn && alpha[8]==turn||alpha[2]==turn && alpha[4]==turn && alpha[6]==turn){
                System.out.println(turn +"\twins");
                break;
            }
            if(turn=='X'){
                turn='O';
            }
            else  {
                turn='X';
            }
        }

    }
}
