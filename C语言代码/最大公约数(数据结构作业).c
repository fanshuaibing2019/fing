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
	printf("������a��b��ֵ:");
	scanf("%d %d",&a,&b);
	printf("���Լ��Ϊ%d",gcd(a,b));
	return 0;
}
