#include<stdio.h>
int main()
{
	int number;
	int count=0;
	int sum=0;
	printf("请输入正整数（输入0结束）\n"); 
	do {
	scanf("%d",&number) ;
	if(number!=0){
		sum+=number;
		count++;
	} 
 } while(number!=0);
 printf("平均数为%.2f",1.0*sum/count);
 return 0;
 } 
