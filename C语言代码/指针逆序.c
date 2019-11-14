#include<stdio.h>
int main()
{
    int i,a[10]={0,1,2,3,4,5,6,7,8,9},temp,*p;
    p=a;
    p+=9;
    for(i=0;i<5;i++,p--)
    {
    	temp=a[i];
    	a[i]=*p;
    	*p=temp;
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
    return 0;
}

