#include<stdio.h>
typedef int elemtype;
typedef struct node{
	elemtype data;
	struct node *next;
}linkstack;
linkstack *top;

linkstack *inistack()
{
	top=(linkstack*)malloc(sizeof(linkstack));
	if(top==NULL)exit(1);
	top->next=NULL;
	return top;
}

linkstack push(linkstack *top,elemtype x)
{
	linkstack *p;
	p=(linkstack*)malloc(sizeof(linkstack));
	p->data=x;
	p->next=top->next;
	top->next=p;
}

linkstack pop(linkstack *top)
{
	linkstack *p;
	elemtype x;
	p=top->next;
	if(p==NULL)printf("у╩ря©у");
	return (NULL);
	else
	{
		top->next=p->next;
		x=p->data;
		free(p);
		return(x); 
	} 
}

elemtype gettop(linkstack *top)
{
	if(top->next!=NULL)return(top->next->data);
	else return(NULL);
}

int empty(linkstack *top)
{
	if(top->next==NULL)return 1;
	else return 0;
}
