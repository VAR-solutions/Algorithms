import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


public class MostRepeatingCharacter {

	static void findMostRepeatingCharacters ( String inputString )
	{
		List< Character > mostRepeatingCharcterList = new ArrayList<Character>();
		Map<Character, Integer> characterCount = new HashMap<Character, Integer>();
		
		//loop for finding the frequncey of each charcter
		for(int i=0;i<inputString.length();i++ )
			{
				if( characterCount.containsKey(inputString.charAt(i)) )
					{
						Integer count =characterCount.get(inputString.charAt(i)) + 1 ;
						characterCount.put( inputString.charAt(i), count );
					}
				else
					{
					characterCount.put( inputString.charAt(i), 1 );
					}
			
			}
		int count =Integer.MIN_VALUE;
		
		//loop for finding the frequency of most repeating charcters
		for( Character keyOfMap: characterCount.keySet() )
			{	
				if (characterCount.get(keyOfMap) >count )
					{
					count = characterCount.get(keyOfMap);			
					}
				
			}
		//loop for finding most repeating characters
		for( Character keyOfMap: characterCount.keySet() )
		{
			if (characterCount.get(keyOfMap) ==count )
				mostRepeatingCharcterList.add(keyOfMap);
			
		}
		
		if( mostRepeatingCharcterList.size()==1 )
		System.out.println("most repeating charcters is " + mostRepeatingCharcterList.get(0));
		else
		{
			System.out.println("Most repeating charcters are");
			for( Character character:mostRepeatingCharcterList )
			{
				System.out.println(character);
			}
		}
	}
	
	public static void main(String[] args) {
		
		System.out.println("Enter the String");
		
		Scanner read = new Scanner(System.in);
		String input = read.nextLine();
		
		//Ensuring that the input is only a number
		while( input.isEmpty() )
		{
			System.out.println("Enter a non empty String");
			input = read.nextLine();
		}
	
		findMostRepeatingCharacters(input);
	}
	
}

