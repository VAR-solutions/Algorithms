import java.util.Random;

public class RandomNumberGenerator {


    public static void main(String[] args) {
        Random random = new Random();

        // make a random number within range of 500
        int randomInt = random.nextInt(500);
        System.out.println(randomInt);

        // makes random integer without any out bound
        int randomInt2 = random.nextInt();
        System.out.println(randomInt2);

        // make a random number without any out bound
        double randomDouble = random.nextDouble();
        System.out.println(randomDouble);

        float randomfloat =random.nextFloat();
        System.out.println(randomfloat);

    }


}
