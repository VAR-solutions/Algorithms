import java.util.Arrays;
import java.lang.Math;

// Function to find length of longest common subsequence between 2 strings.
// Recursive, TopDown & BottomUp approaches implemented.

class LCS{
    public static void main(String[] args){
        String s1 = "Vishal";
        String s2 = "Vashist";
        int m = s1.length(), n = s2.length();
        int[][] TP = new int[m+1][n+1];
        for(int i=0;i<m+1;i++){
            Arrays.fill(TP[i], -1);
        }
        System.out.print("Length of longest common subsequence - " + lcsBottomUp(s1, s2, m, n));
        System.out.println();
    
    }

    static int lcsRecursive(String s1, String s2, int m, int n){
        if(m==0 || n==0) return 0;
        if(s1.charAt(m-1)==s2.charAt(n-1)) return 1 + lcsRecursive(s1,s2,m-1,n-1);
        else return Math.max(lcsRecursive(s1,s2,m-1,n), lcsRecursive(s1,s2,m,n-1));
    }

    static int lcsTopDown(String s1, String s2, int m, int n, int[][] TP){
        if(m==0 || n==0) return 0;
        if(TP[m][n]!=-1) return TP[m][n];
        if(s1.charAt(m-1)==s2.charAt(n-1)) return TP[m][n] = 1 + lcsTopDown(s1,s2,m-1,n-1,TP);
        else return TP[m][n] = Math.max(lcsTopDown(s1,s2,m-1,n,TP), lcsTopDown(s1,s2,m,n-1,TP));
    }

    static int lcsBottomUp(String s1, String s2, int m, int n){
        int[][] DP = new int[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) DP[i][j] = 0;
                else if(s1.charAt(i-1)==s2.charAt(j-1)) DP[i][j] = 1 + DP[i-1][j-1];
                else DP[i][j] = Math.max(DP[i-1][j], DP[i][j-1]);
            }
        }
        return DP[m][n];
    }

}
