public class KMP {

	public static void main(String[] args) {

		String text="piyushpiy";
		String pat="piy";

		int n = text.length();
		int m = pat.length();
		
		int i=0,j=0;
		int[] LPS = getLps(pat, m);

		while( i< ) {
			if(text.charAt(i)==pat.charAt(j)){
				i++; j++;
			}
			
			if(j==m){
				  System.out.println("Found pattern at index " + (i - j));
				  j=LPS[j-1];
			}
			else if(i < n&& pat.charAt(j) != text.charAt(i)) {
				
				if(j!=0)
					j=LPS[j-1];
				else
					i++;
				
			}
		}
	}

	public static int[] getLps(String pat, int m) {
		int[] LPS = new int[m];
		int i = 1;
		LPS[0] = 0;
		int len = 0;
		while (i < m) {
			if (pat.charAt(i) == pat.charAt(len)) {
				len++;
				LPS[i] = len;
				i++;
			} else {
				if (len > 0) {
					len = LPS[len - 1];
				} else {
					LPS[i] = len;
					i++;
				}
			}
		}
		
		return LPS;
	}
}