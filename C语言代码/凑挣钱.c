#include<stdio.h>
int main()
{
	int x;
	int one,two,five;
	scanf("%d",&x);
	for(one=1;one<x*10;one++){
		printf("壹%d",one);
		for(two=1;two<x*10/2;two++){
			printf("贰%d",two);
			for(five=1;five<x*10/5;five++){
				printf("伍%d  ",five);
				if(one+two*2+five*5==x*10){
					printf("可以用%d个一角%d个两角%d个五角得到%d元\n",one,two,five,x);
				}
			}
		}
	}
	return 0;
 } 
