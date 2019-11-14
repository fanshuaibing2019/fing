#include<stdio.h>
int main()
{
	int fact=1;
	int n;
	int x=1;
	scanf("%d",&n);
	while(x<=n){
		fact*=x;
		x++;
	}
	printf("%d!=%d",n,fact);
	return 0;
 } 
