#include<stdio.h>
#include<stdlib.h>
#define OK		1
#define ERROR 	0
typedef char elemtype;
typedef struct dualnode{
	elemtype date;
	struct dualnode *prior,*next;
}dulinklist;

void inilinklist(dulinklist *L)
{
	dulinklist *p,*q;
	int i;
	L=(dulinklist*)malloc(sizeof(dulinklist));

	L->next=L->prior=NULL;
	p=L;
	for(i=0;i<26;i++)
	{
		q=(dulinklist*)malloc(sizeof(dulinklist));
		q->date='A';
		q->prior=p;
		q->next=p->next;
		p->next=q;
		p=q;
	}
	p->next=L->next;
	L->next->prior=p;
}

void caesar(dulinklist *L,int n)
{
	if(n>0)
	{
		do
		{
			L=L->next;
		}while(--n);
	}
	if(n<0)
	{
		do
		{
			L=L->next;
		}while(++n);
	}
}

int main()
{
	dulinklist *L;
	int i,n;
	inilinklist(L);
	printf("请输入一个整数：");
	fflush(stdin);
	scanf("%d",&n);
	printf("\n");
	caesar(L,n);
	
	for(i=0;i<26;i++)
	{
		L=L->next;
		printf("%c",L->date);
	} 
	
	return 0;
}
