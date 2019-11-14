#include<stdio.h>
typedef int elemtype;
typedef struct node{
	elemtype data;
	struct node *next;
}linklist; 
linklist *creatlist(int n)
{
	int x,k;
	linklist *head,*r,*p;
	p=(linklist*)malloc(sizeof(linklist));//构建头结点空间
	head=p;
	p->next=NULL;
	r=p;
	for(k=1;k=n;k++){
		scanf("%d",&x);
		p=(linklist*)malloc(sizeof(linklist));
		p->data=x;
		p->next=NULL;
		r->next=p;
		r=r->next;
	} 
	return head;
}
