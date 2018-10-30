import java.security.SecureRandom;
/**
 * A Java program to generate a random number with java.security.SecureRandom
 * which is harder to predict than a number generated with java.util.Random.
 *
 * This is because java.util.Random uses the system clock as its seed and this can be
 * reproduced more easily. On the other hand java.security.SecureRandom takes random
 * data from your os and uses that as its seed. This makes it hard to predict the randomly
 * generated number.
 *
 * In programs where high security is mandatory, you might consider using java.util.SecureRandom.
 */
public class generateSecureRandom {

	public static void main(String[] args) {
		// create instance of SecureRandom class
		SecureRandom secureRand = new SecureRandom();

		// Generate random integers in range 0 to 999
		int secureRand_int1 = secureRand.nextInt(1000);
		int secureRand_int2 = secureRand.nextInt(1000);

		// Print random integers
		System.out.println("Random Integers: " + secureRand_int1);
		System.out.println("Random Integers: " + secureRand_int2);

		// Generate Random doubles
		double rand_dub1 = secureRand.nextDouble();
		double rand_dub2 = secureRand.nextDouble();

		// Print random doubles
		System.out.println("Random Doubles: " + rand_dub1);
		System.out.println("Random Doubles: " + rand_dub2);
	}

}
