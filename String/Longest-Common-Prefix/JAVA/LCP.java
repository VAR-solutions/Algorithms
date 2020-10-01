package com.CP;

/*
Sample test cases :-

1) Input: ["flower","flow","flight"]
    Output: "fl"

2) Input: ["dog","racecar","car"]
    Output: ""

*/
import java.util.*;

class LCP {

	public static void main(String[] args) {
		String str[] = { "flower", "flow", "flight" };
		String result = longestCommonPrefix(str);

		System.out.println("Longest Common Prefix is : " + result);

	}

	public static String longestCommonPrefix(String[] str) {

		if (str.length == 0)
			return "";
		String ans = "";

		Arrays.sort(str);

		int min = Integer.MAX_VALUE;
		for (String s : str) {
			min = Math.min(min, s.length());
		}

		int count = 0;

		for (int i = 0; i < min; i++) {
			if (str[0].charAt(i) == str[str.length - 1].charAt(i))
				// ans+=str[0].charAt(i); this line consumes time
				count++;
			else
				break;
		}

		return str[0].substring(0, count);

	}

}
