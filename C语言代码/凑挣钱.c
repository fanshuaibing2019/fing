#include<stdio.h>
int main()
{
	int x;
	int one,two,five;
	scanf("%d",&x);
	for(one=1;one<x*10;one++){
		printf("Ҽ%d",one);
		for(two=1;two<x*10/2;two++){
			printf("��%d",two);
			for(five=1;five<x*10/5;five++){
				printf("��%d  ",five);
				if(one+two*2+five*5==x*10){
					printf("������%d��һ��%d������%d����ǵõ�%dԪ\n",one,two,five,x);
				}
			}
		}
	}
	return 0;
 } 
