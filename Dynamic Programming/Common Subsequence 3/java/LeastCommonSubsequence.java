
import java.io.*; 

class  LongestCommonSubsequence 
{ 
    // Returns length of LCS for X[0..m-1], Y[0..n-1] 
    static void lcs(int[] X, int[] Y, int m, int n) 
    { 
        int[][] L = new int[m+1][n+1];  
        for (int i=0; i<=m; i++) 
        { 
            for (int j=0; j<=n; j++) 
            { 
                if (i == 0 || j == 0) 
                    L[i][j] = 0; 
                else if (X[i-1] == Y[j-1]) 
                    L[i][j] = L[i-1][j-1] + 1; 
                else
                    L[i][j] = Math.max(L[i-1][j], L[i][j-1]); 
            } 
        }
        int index = L[m][n]; 
        int temp = index;
        int[] lcs = new int[index+1]; 
        lcs[index] = ' ';
        int i = m, j = n; 
        while (i > 0 && j > 0) 
        { 
            if (X[i-1] == Y[j-1]) 
            { 
                lcs[index-1] = X[i-1];  
                  
                i--;  
                j--;  
                index--;      
            } 
            else if (L[i-1][j] > L[i][j-1]) 
                i--; 
            else
                j--; 
        } 

        for(int k=0;k<temp;k++) 
            System.out.print(lcs[k]+" ");
        
    } 
      
    public static void main (String[] args)  
    { 

    	int[] X={1,2,3,4,1};
    	int[] Y={3,4,1,2,1,3};
        int m = X.length; 
        int n = Y.length; 
        lcs(X, Y, m, n); 
    } 
} 
