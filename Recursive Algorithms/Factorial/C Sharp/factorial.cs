using System;

namespace Dungeon
{
	class MainClass
	{
		public static int fact(int n){
			if(n == 0){
				return 1;
			}else{
				return n*fact(n-1);
			}
		}

		public static void Main (string[] args)
		{
			//Console.WriteLine(fact(7));
		}
	}
}
