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
	printf("\n\t\t��������ӵ�����Ԫ��:");
	scanf("%d",&x);
	if(p.front==(p.rear+1)%MAXSIZE)
	{
		printf("\n\t\t�����������������!\n");
	}
	else
	{
		p.rear=(p.rear+1)%MAXSIZE;
		p.data[p.rear]=x;
		printf("\n\t\t��ӳɹ�!\n");
	}
}

void outqueue()
{
	if(p.front==p.rear)
	{
		printf("\n\t\t����Ϊ��!\n");
	}
	else
	{
		p.front=(p.front+1)%MAXSIZE;
		printf("\n\t\t���ӳɹ�!\n\t\t����Ԫ��Ϊ%d!\n",p.data[p.front]);
		
	}
}

void showqueue()
{
	int n;
	printf("\n\t\t");
	if(p.front==p.rear)
	{
		printf("\n\t\t����Ϊ��!\n");
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
	printf("\n\t\t���г���Ϊ%d!",(p.rear+MAXSIZE-p.front)%MAXSIZE);
}

void main()
{
	int choice;
	int n=1;
	iniqueue();
	while(n)
	{
		printf("\n\n\t\t**********************************\n");
		printf("\t\t*         1-----��  ��           *\n");
		printf("\t\t*         2-----��  ��           *\n");
		printf("\t\t*         3-----��ʾ��           *\n");
		printf("\t\t*         4-----��ӳ�           *\n");
		printf("\t\t*         0-----��  ��           *\n");
		printf("\t\t**********************************\n");
		printf("\n\t\t������ָ��(0-4):");
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
				printf("������������������!\n");
				break;
		}
	}
}

