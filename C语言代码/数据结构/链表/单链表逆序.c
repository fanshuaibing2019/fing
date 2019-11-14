#include<stdio.h>
#include<stdlib.h>
typedef struct lnode{
	char data;
	struct lnode *next;
}lnode;

lnode *hl;


void creatlnode()
{
	lnode *p,*q;
	int n=6;
	char x='a';
	q=(lnode*)malloc(sizeof(lnode));
	hl=q;
	while(n--)
	{
		p=(lnode*)malloc(sizeof(lnode));
		p->data=x++;
		p->next=NULL;
		q->next=p;
		q=p;
	}
	q=hl;
	hl=hl->next;
	free(q);
}

void printlnode()
{
	lnode *p;
	p=hl;
	while(p!=NULL)
	{
		printf("%c ",p->data);
		p=p->next;
	}
}

void swaplnode()
{
	lnode *p,*q,*r;
	p=hl;
	q=NULL;
	while(p->next!=NULL)
	{
		r=p->next;
		p->next=q;
		q=p;
		p=r;
	}
	p->next=q;
	hl=p;
}

void main()
{
	creatlnode();
	swaplnode();
	printlnode();
}
