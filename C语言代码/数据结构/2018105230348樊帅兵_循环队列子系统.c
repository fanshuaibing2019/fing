#include<stdio.h>
#define MAXSIZE 10
typedef struct {
	int data[MAXSIZE];
	int front,rear;
}csequeue;

csequeue p;

void iniqueue()
{
	p.front=p.rear=MAXSIZE-1;
}

void inqueue()
{
	int x;
	printf("\n\t\t请输入入队的整数元素:");
	scanf("%d",&x);
	if(p.front==(p.rear+1)%MAXSIZE)
	{
		printf("\n\t\t队列已满，不能入队!\n");
	}
	else
	{
		p.rear=(p.rear+1)%MAXSIZE;
		p.data[p.rear]=x;
		printf("\n\t\t入队成功!\n");
	}
}

void outqueue()
{
	if(p.front==p.rear)
	{
		printf("\n\t\t队列为空!\n");
	}
	else
	{
		p.front=(p.front+1)%MAXSIZE;
		printf("\n\t\t出队成功!\n\t\t出队元素为%d!\n",p.data[p.front]);
		
	}
}

void showqueue()
{
	int n;
	printf("\n\t\t");
	if(p.front==p.rear)
	{
		printf("\n\t\t队列为空!\n");
	}
	else
	{
		n=p.front;
		while(n!=p.rear)
		{
			n=(n+1)%MAXSIZE;
			printf("%d ",p.data[n]);
		}
	}
}

void lenqueue()
{
	printf("\n\t\t队列长度为%d!",(p.rear+MAXSIZE-p.front)%MAXSIZE);
}

void main()
{
	int choice;
	int n=1;
	iniqueue();
	while(n)
	{
		printf("\n\n\t\t**********************************\n");
		printf("\t\t*         1-----入  队           *\n");
		printf("\t\t*         2-----出  队           *\n");
		printf("\t\t*         3-----显示队           *\n");
		printf("\t\t*         4-----求队长           *\n");
		printf("\t\t*         0-----返  回           *\n");
		printf("\t\t**********************************\n");
		printf("\n\t\t请输入指令(0-4):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				inqueue();
				break;
			case 2:
				outqueue();
				break;
			case 3:
				showqueue();
				break;
			case 4:
				lenqueue();
				break;
			case 0:
				n=0;
				break;
			default :
				printf("输入有误，请重新输入!\n");
				break;
		}
	}
}

