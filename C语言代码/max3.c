#include<stdio.h>  
int main()
{
	int max(int x,int y,int z);
	int a,b,c,d;
	scanf("%d,%d,%d",&a,&b,&c);
	d=max(a,b,c);
	printf("max=%d\n",d);
	return 0;
}
int max(int x,int y,int z)
{
	int w;
	if(x>y)w=x;
	else w=y;
	if(w>z)w=w;
	else w=z;
	return (w);
}
