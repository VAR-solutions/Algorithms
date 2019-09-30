import java.util.Scanner;

public class Floyds {
    public static int min(int a,int b){
        return a>b?b:a;
    }

    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        System.out.print("\nEnter the number of nodes: ");
        int n = in.nextInt();
        int [][]mat = new int[n][n];
        System.out.println("Enter the matrix");
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j]=in.nextInt();

	//The holy grail of this algorithm!
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);


        System.out.println("Result matrix");
        for(int i=0;i<n;i++) {
            for (int j = 0; j < n; j++)
                System.out.print(" " + mat[i][j]);
            System.out.println();
        }
    }
}
