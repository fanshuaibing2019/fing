#include<stdio.h>
int main()
{
	int number;
	int count=0;
	int sum=0;
	printf("������������������0������\n"); 
	do {
	scanf("%d",&number) ;
	if(number!=0){
		sum+=number;
		count++;
	} 
 } while(number!=0);
 printf("ƽ����Ϊ%.2f",1.0*sum/count);
 return 0;
 } 
