#include<stdio.h>
int main()
{
	int hour1,minute1;
	int hour2,minute2;
	scanf("%d %d",&hour1,&minute1);
	scanf("%d %d",&hour2,&minute2);
	int h1=hour2-hour1;
	int m1=minute2-minute1;
	if(m1<0){m1+=60;
	h1--;
	}
	printf("时间差是%d小时%d分",h1,m1);
	return 0;
 } 
