#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int i;
	int isprime=1;
	for(i=2;i<x-1;i++){
		if(x%i==0)
		{
		isprime=0;
		break;
	    }
	}
	if(isprime)
	{
		printf("������");
	}else{
	printf("��������"); 
	}
	
	return 0;
}
