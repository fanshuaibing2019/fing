#include<stdio.h>
int gcd(int a,int b)
{
	int r=a%b;
	if(r==0)return b;
	else return gcd(b,r);
}
int main()
{
	int a,b;
	printf("请输入a、b的值:");
	scanf("%d %d",&a,&b);
	printf("最大公约数为%d",gcd(a,b));
	return 0;
}
