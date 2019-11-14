#include<stdio.h>
int main(int argc,char const*argv[])
{void sort(int*x,int n);
	int i,*p,a[10];
	p=a;
	printf("please enter 10 integer numbers:");
	for(i=0;i<10;i++)
	scanf("%d ",p++);
	p=a;
	sort(p,10);
	for(i=0;i<10;i++)
	printf("%d ",p++);
	printf("\n");
	return 0;
}
void sort(int*x,int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(*(x+j)>*(x+k))
				k=i;
			if(k!=i)
			{
				t=*(x+i);
				*(x+i)=*(x+k);
				*(x+k)=t;
				
			}
	}
}
