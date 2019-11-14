#include<stdio.h>
typedef int elemtype;
typedef struct node{
	elemtype data;
	struct node *next;
}linklist; 
linklist_clear(linklist *l)
{
	linklist *p,*q;
	p=l->next;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	l->next=NULL;
	return ok;
}
