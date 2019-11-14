#include<stdio.h>
#include<stdlib.h>
#define OK		1
#define ERROR 	0
typedef char elemtype;
typedef int status;
typedef struct dualnode{
	elemtype date;
	struct dualnode *prior,*next;
}dulinklist;

status inilinklist(dulinklist *L)
{
	dulinklist *p,*q;
	int i;
	L=(dulinklist*)malloc(sizeof(dulinklist));

	L->next=L->prior=NULL;
	p=L;
	for(i=0;i<26;i++)
	{
		q==(dulinklist*)malloc(sizeof(dulinklist));
		if(!q)return ERROR;
		q->date='A'+i;
		q->prior=p;
		q->next=p->next;
		p->next->prior=q;
		p->next=q;
		p=q;
	}
	p->next=L->next;
	L->next->prior=p;
	return OK;
}

void caesar(dulinklist *L,int i)
{
	if(i>0)
	{
		do
		{
			L=L->next;
		}while(--i);
	}
	if(i<0)
	{
		do
		{
			L=L->next;
		}while(++i);
	}
}

int main()
{
	dulinklist *L;
	int i,n;
	printf("请输入一个整数：");
	inilinklist(L);
	
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
