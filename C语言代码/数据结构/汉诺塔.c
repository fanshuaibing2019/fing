#include<stdio.h>
void move(int n,char x,char y,char z)
{
	if(1==n)
	{
		printf("%c-->%c\n",x,z);
	}
	else
	{
		move(n-1,x,z,y);			//��n-1�����Ӵ�x����z�ƶ���y�� 
		printf("%c-->%c\n",x,z);	//����n�����Ӵ�x�ƶ���z�� 
		move(n-1,y,x,z);			//��n-1�����Ӵ�y����x�Ƶ�z 
	}
}
int main()
{
	int n;
	printf("�����뺺ŵ���Ĳ�����");
	scanf("%d",&n);
	printf("�ƶ��Ĳ������£�\n");
	move(n,'1','2','3');
	return 0; 
 } 
