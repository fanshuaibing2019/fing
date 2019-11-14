#include<stdio.h>
int main(int argc,char const *argv[])
{
	int *p,i,a[10];
	p=a;
	printf("please enter 10 integer numbers:");
	for(i=0;i<10;i++)
	scanf("%d",p++);
	for(i=0;i<10;i++,p++)
	printf("%d ",*p);
	return 0; 
}
