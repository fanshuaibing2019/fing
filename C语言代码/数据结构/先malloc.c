#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef char elemtype;
typedef struct dualnode{
	elemtype data;
	struct dualnode *prior,*next;
}dulinklist;
dulinklist *L;

void inilinklist(dulinklist *L)
{
	dulinklist *p,*q;
	int i;
	
	q=L;
	for(i=0;i<26;i++)
	{
		p=(dulinklist*)malloc(sizeof(dulinklist));
		p->data='A'+i;
		p->next=q->next;
		p->prior=q;
		q->next=p;
		q=p;
	}
	p->next=L->next;
	L->next->prior=p;
}

void caesar(dulinklist *L,int i)
{
	if(i>0)
	{
		L=L->next;
		for(;i>0;i--)L=L->next;
	}
	if(i<0)
	{
		L=L->next;
		for(;i<0;i++)L=L->prior;
	}
}

int main()
{
	int i;
	L=(dulinklist*)malloc(sizeof(dulinklist));
	L->next=L->prior=NULL;
	inilinklist(L);
	printf("请输入一个整数：");
	fflush(stdin);
	scanf("%d",&i);
	caesar(L,i);
	printf("\n");
	for(i=0;i<26;i++)
	{
		printf("%c",L->data);
		L=L->next;
	}
	return 0;
}
