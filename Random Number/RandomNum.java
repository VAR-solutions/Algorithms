import java.util.Random;

public class RandomNum {

	//get random number
	public static int randInt(int min, int max){
		Random rand = new Random();
		int randNum = min + rand.nextInt(max - min + 1);
		return randNum;
	}
	public static void main(String[] args) {
		System.out.println(randInt(1, 100));
	}

}
