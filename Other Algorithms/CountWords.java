package strings;

public class CountWords {
	
	static int countWords(String str)
	{
		int count= 0;
		for(int i=0; i< str.length(); i++)
		{
			if(str.charAt(i) == ' ')
			{
				count++;
			}
		}
		return count+1;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String s ="This is a test match";
		System.out.println(countWords(s));


	}

}
