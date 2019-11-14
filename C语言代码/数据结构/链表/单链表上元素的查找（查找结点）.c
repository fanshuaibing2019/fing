#include<stdio.h>
typedef int elemtype;
typedef struct node{
	elemtype data;
	struct node *next;
}linklist; 
linklist *find(linklist *head,int i)
{
	int j;
	linklist *p;
	p=head->next;
	j=1;
	while(p!=NULL && j<i){
		p=p->next;
		j++;
	}
	return p;
}

