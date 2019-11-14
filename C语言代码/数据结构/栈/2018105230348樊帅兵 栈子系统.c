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
		printf("\n\t\tջΪ�գ�\n");
	else
	{
		printf("\n\t\tջԪ��Ϊ��");
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
	printf("\n\t\tת����Ķ�������ֵΪ��");
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
		printf("\n\t\t             ջ��ϵͳ              ");
		printf("\n\t\t***********************************");
		printf("\n\t\t*          1--��ջ                *"); 
		printf("\n\t\t*          2--��ջ                *"); 
		printf("\n\t\t*          3--��ʾ                *"); 
		printf("\n\t\t*          4--����ת��            *"); 
		printf("\n\t\t*          0--�˳�                *"); 
		printf("\n\t\t***********************************");
		printf("\n\t\t��ѡ��ѡ�");
		fflush(stdin);
		choice=getchar();
		switch(choice)
		{
			case '1':
				j=1;
				while(j)
				{
					printf("������һ������������0��������");
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
					printf("\n\t\t��ջԪ��Ϊ:%d\n",pop(s));
				else
					printf("\n\t\tջ�ѿգ����ܳ�ջ��\n");
				break;
			case '3':
				showstack(s);
				break;
			case '4':
				printf("������һ��ʮ����������");
				scanf("%d",&val);
				conversion(val);
				break;
			case '0':
				i=0;
		 } 
	}
}
