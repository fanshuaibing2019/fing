#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int fact=1;
	for(i=n;i>1;i--){
		fact*=i;
	}printf("%d!=%d\n%d",n,fact,i); 
return 0;
}
