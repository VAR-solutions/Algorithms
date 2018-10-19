package Recursioncontd;

public class PrintPemutations {

	public static void main(String[] args) {
		String s = "abc";
		PrintPermutations2(s, "");
		StringBuilder s1 = new StringBuilder("abc");
		StringBuilder s2 = new StringBuilder();
		//PrintPermutations1SB(s1, s2);
		//PrintPermutations1SB(s1, s2);

	}
	
public static void PrintPermutations2(String str, String asf) {
		
		if(str.length()==0) {
			System.out.println(asf);
			return;
		}
		char ch = str.charAt(0);
		String roq = str.substring(1);
		for(int i=0; i<=asf.length(); i++) {
			String l = asf.substring(0, i);
			String r = asf.substring(i);
			PrintPermutations2(roq, r+ch+l);
		}
		
	}
	
	public static void PrintPermutations1(String str, String asf) {
		
		if(str.length()==0) {
			System.out.println(asf);
			return;
		}
		
		for(int i=0; i<str.length(); i++) {
			char ch = str.charAt(i);
			PrintPermutations1(str.substring(0,i)+str.substring(i+1), asf+ch);
		}
		
	}
	
	public static void PrintPermutations1SB(StringBuilder s1, StringBuilder s2) {
		
		if(s1.length() == 0) {
			System.out.println(s2);
			return;
		}
		char ch = s1.charAt(0);
		
		s1.deleteCharAt(0);
		
		for(int i=0; i<=s2.length(); i++) {
			s2.insert(i, ch);
			PrintPermutations1SB(s1, s2);
			s2.deleteCharAt(i);
		}
		s1.insert(0, ch);
		
	}
	
	
	
public static void PrintPermutations2SB(StringBuilder s1, StringBuilder s2) {
		
		if(s1.length() ==0) {
			System.out.println(s2);
			return;
		}
		
		for(int i=0; i<s1.length(); i++) {
			
			char ch = s1.charAt(i);
			s1.deleteCharAt(i);
			s2.insert(0, ch);
			
			
			
			PrintPermutations2SB(s1, s2);
			s2.deleteCharAt(0);
			s1.insert(i, ch);
			
			
		}
		
		
	}
	

}
