#include<stdio.h>
int main() 
{
	int x;
	scanf("%d",&x);
	int f;
	if(x<0)
	{f=-1;
	}else if(x==0)
	{f=0;
	}else if(x>5)
	{f=3*x;
	}else {f=2*x;
	}
	printf("f=%d",f);
	return 0;
}
