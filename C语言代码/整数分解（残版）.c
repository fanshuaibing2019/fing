#include<stdio.h>
int main()
{
	int x,a=0,b;
	scanf("%d",&x);
	for(;x>0;x/=10){
		a=10*a+x%10;
	}
	x=a;
	printf("%d\n",x);
	for(;x>0;x/=10)
	{
		b=x%10;
		printf("%d ",b);
	}
	return 0;
} 
