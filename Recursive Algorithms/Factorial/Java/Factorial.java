public class Factorial {
    public static int factorial(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        int edge1 = factorial(0);
        int edge2 = factorial(1);
        int typical = factorial(5);
        assert(edge1 == 1);
        assert(edge2 == 1);
        assert(typical == 120);
    }
}