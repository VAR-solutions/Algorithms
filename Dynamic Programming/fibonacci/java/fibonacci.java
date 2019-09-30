public class Fibonacci {
  public static void main(String[] args) {
    int n = 9;
    System.out.println("Fib(" + n + "): " + fib(n));
  }

  // fibonacci using dynamic programming
  public static int fib(int n) {
    if (n == 0) return 0; // Special case for 0

    int f[] = new int[2];

    // Initial values of fibonacci series
    f[0] = 1;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
      // Use modulus to switch array indexes
      f[i%2] = f[0] + f[1];
    }

    return f[(n+1)%2];
  }
}
