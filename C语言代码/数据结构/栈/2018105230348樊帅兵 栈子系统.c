#include<stdio.h>
#include<stdlib.h>
#define STACKMAC 100

typedef struct stacknode{
	int data;
	struct stacknode *next;
}stacknode;

typedef struct{
	stacknode *top;
}linkstack;
 
void push(linkstack *s,int x)
{
	stacknode *p=(stacknode*)malloc(sizeof(stacknode));
	p->data=x;
	p->next=s->top;
	s->top=p;
}

int pop(linkstack *s)
{
	int x;
	stacknode *p=s->top;
	x=p->data;
	s->top=p->next;
	free(p);
	return x;
}

void showstack(linkstack *s)
{
	stacknode *p=s->top;
	if(p==NULL)
		printf("\n\t\t栈为空！\n");
	else
	{
		printf("\n\t\t栈元素为：");
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next; 
		} 
		printf("\n");
	}
}

void conversion(int n)
{
	linkstack *s=(linkstack*)malloc(sizeof(linkstack));
	int x;
	s->top=NULL;
	do
	{
		x=n%2;
		n/=2;
		stacknode *p=(stacknode*)malloc(sizeof(stacknode));
		p->next=s->top;
		p->data=x;
		s->top=p;
	}while(n);
	printf("\n\t\t转换后的二进制数值为：");
	while(s->top)
	{
		printf("%d",s->top->data);
		s->top=s->top->next;
	}
	printf("\n");
}

void main()
{
	int i=1,j=1,choice,val,n;
	linkstack *s=(linkstack*)malloc(sizeof(linkstack));
	s->top=NULL;
	while(i)
	{
		printf("\n");
		printf("\n\t\t             栈子系统              ");
		printf("\n\t\t***********************************");
		printf("\n\t\t*          1--进栈                *"); 
		printf("\n\t\t*          2--出栈                *"); 
		printf("\n\t\t*          3--显示                *"); 
		printf("\n\t\t*          4--数制转换            *"); 
		printf("\n\t\t*          0--退出                *"); 
		printf("\n\t\t***********************************");
		printf("\n\t\t请选择选项：");
		fflush(stdin);
		choice=getchar();
		switch(choice)
		{
			case '1':
				j=1;
				while(j)
				{
					printf("请输入一个整数（输入0结束）：");
					scanf("%d",&val);
					getchar();
					if(val!=0)
					{
						push(s,val);
					}
					else
					{
						j=0;
					}
				}
				break;
			case '2':
				if(s->top!=NULL)
					printf("\n\t\t出栈元素为:%d\n",pop(s));
				else
					printf("\n\t\t栈已空，不能出栈！\n");
				break;
			case '3':
				showstack(s);
				break;
			case '4':
				printf("请输入一个十进制整数：");
				scanf("%d",&val);
				conversion(val);
				break;
			case '0':
				i=0;
		 } 
	}
}
