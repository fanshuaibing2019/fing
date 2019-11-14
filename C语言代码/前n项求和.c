#include<stdio.h>
int main()
{
	int n,a=1;
	double x=0;
	for(n=1;n<=100;n++){
		x+=1.0/n*a;
		a=-a;
	}
	printf("%f",x);
	return 0;
}
