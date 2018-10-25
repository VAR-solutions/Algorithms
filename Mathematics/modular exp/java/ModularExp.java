public class ModularExp {
	// computes n raised to the nonnegative power e modulo m
	public static long exp(long n, int e, int m) {
		if (e == 0) {
			return 1L;
		}

		n %= m;
		long ans = 1;

		if (e%2 == 0) {
			return exp(ans*ans, e/2, m);
		}
		else {
			return n*exp(ans*ans, e/2, m);
		}
	}
	
	public static void main(String[] args) {
		long n = 137;
		int e = 207;
		int m = 18;
		System.out.println(exp(n,e,m));
	}
}
