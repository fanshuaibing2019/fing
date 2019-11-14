#include<stdio.h>
int main()
{
	int price=0;
	int x=0;
printf("请输入金额(元):");
scanf("%x",&price);
printf("请输入票面(元):");
scanf("%x",&x);
int change=x-price;
printf("找您%d元",change);
return(0); 
}
