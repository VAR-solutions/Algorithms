#include <stdio.h>


int main()
{
	int num, ans;
	int fact=1,i=1;
	int factorial(int n);

	printf("Enter number whose factorial is to be found\n");
	scanf("%d",&num);
	ans=factorial(num);
	printf("factorial is %d",ans);

	return 0;
}
int factorial(int n){
	int res=n;
	if (res=0|| res=1) return 1;
	if (res>1){
		res*=factorial(n-1);
	}
	return res;
}
