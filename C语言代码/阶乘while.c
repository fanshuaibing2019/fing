#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int b=x;
	int a=x;
	while(b>1){a=a*(b-1);
	b--;
		
	}printf("%d!=%d",x,a);
	return 0;
}
