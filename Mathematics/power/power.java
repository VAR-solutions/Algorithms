import java.util.Scanner;
class p{
long func(long x, long y) 
{ 
	long temp; 
	if( y == 0) 
	return 1; 
	temp = func(x, y/2);	 
	if (y%2 == 0) 
		return temp*temp; 
	else
	{ 
		if(y > 0) 
			return x*temp*temp; 
		else
			return (temp*temp)/x; 
	} 
} 
}
class power{
public static void main(String args[]){
Scanner sc = new Scanner(System.in);
long x = sc.nextLong();
long y = sc.nextLong();
p P = new p();
System.out.println(""+P.func(x,y));
}
}
