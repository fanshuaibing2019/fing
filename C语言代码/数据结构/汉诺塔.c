#include<stdio.h>
void move(int n,char x,char y,char z)
{
	if(1==n)
	{
		printf("%c-->%c\n",x,z);
	}
	else
	{
		move(n-1,x,z,y);			//将n-1个盘子从x借助z移动到y上 
		printf("%c-->%c\n",x,z);	//将第n个盘子从x移动到z上 
		move(n-1,y,x,z);			//将n-1个盘子从y借助x移到z 
	}
}
int main()
{
	int n;
	printf("请输入汉诺塔的层数：");
	scanf("%d",&n);
	printf("移动的步骤如下：\n");
	move(n,'1','2','3');
	return 0; 
 } 
