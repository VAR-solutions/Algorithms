import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Swap {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
    // Input 2 integers
    int a = Integer.parseInt(br.readLine());
		int b = Integer.parseInt(br.readLine());
		a = a^b;
		b = a^b;
		a = a^b;
    
    // Integers swapped
		System.out.println(a +" "+ b);
	}
}
