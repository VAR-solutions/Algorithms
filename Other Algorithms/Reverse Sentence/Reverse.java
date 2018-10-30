package strings;

public class Reverse {
	
	static String reverseEachWord(String input)
	{
		String words[] = input.split("\\s");
		String revstring = "";
		
		for(int i=0; i<words.length; i++)
		{
			String indiword = words[i];
			String s = "";
			
			for(int j=indiword.length()-1; j>=0; j--)
			{
				s += indiword.charAt(j);
			}
			
			revstring = revstring + s + " ";
			
		}
		
		return revstring;
	}
	
	public static void main(String[] args) 
	{
		String str ="Welcome to coding ninjas";
		System.out.println(reverseEachWord(str));

	}

}
