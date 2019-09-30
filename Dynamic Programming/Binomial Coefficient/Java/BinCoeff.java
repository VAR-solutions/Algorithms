class BinCoeff {
    static int binomialCoeff(int n, int k) {
        int C[][] = new int[n + 1][k + 1];
        int i, j;

        for (i = 0; i <= n; i++) {
            for (j = 0; j <= min(i, k); j++) {
                
                if (j == 0 || j == i)
                    C[i][j] = 1;

                else
                    C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }

        return C[n][k];
    }

    static int min(int a, int b) {
        return (a < b) ? a : b;
    }

    public static void main(String args[]) {
        int n = 5, k = 2;
        System.out.println("Value of C(" + n + "," + k + ") is " + binomialCoeff(n, k));
    }
}
