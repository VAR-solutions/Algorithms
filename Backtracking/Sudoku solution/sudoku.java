
import java.util.*;

class Sudoku {

    public static void main(String[] args) {
        int[][] board = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

        solveSuduko(board, 0, 0);

    }

    

    //display the soluko board

    public static void display(int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void solveSuduko(int[][] board, int i, int j) {
        if (i == board.length) {
            display(board);
            return;
        }
        int ni = 0;
        int nj = 0;

        if (j == board[0].length - 1) {
            ni = i + 1;
            nj = 0;
        } else {
            ni = i;
            nj = j + 1;
        }
        if (board[i][j] != 0) {
            solveSuduko(board, ni, nj);
        } else {
            for (int val = 1; val <= 9; val++) {
                if (isValid(board, i, j, val)) {
                    board[i][j] = val;
                    solveSuduko(board, ni, nj);
                    board[i][j] = 0;
                }
            }
        }
    }

    //checks if the move is valid or not 
    public static boolean isValid(int[][] board, int x, int y, int val) {
        int n = board.length;
        for (int i = 0; i < n; i++) {
            if (board[x][i] == val) {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][y] == val) {
                return false;
            }
        }

        x = x / 3 * 3;
        y = y / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[x + i][y + j] == val) {
                    return false;
                }
            }
        }

        return true;
    }

}
