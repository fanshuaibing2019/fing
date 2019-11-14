#include<stdio.h>
int main()
{
	char ac[]={0,1,2,3,4,5,6,7,8,9};
	char *p=ac;
	char *p1=(ac+5);
	printf("%p\n",p);
	printf("%p\n",p+1);
	printf("%d\n",p1-p);
	printf("%d\n",*(p+3));
	int ai[]={0,1,2,3,4,5,6,7,8,9};
	int *q=ai;
	printf("%p\n",q);
	printf("%p\n",q+1);
	return 0;
}
