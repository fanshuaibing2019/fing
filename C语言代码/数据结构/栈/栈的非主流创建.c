#include<stdio.h>
#include<stdlib.h> 
#define STACKINCREMENT 10
typedef struct{
	int *base;
	int *top;
	int stacksize;
}sqstack;

void push(sqstack *s,int e)
{
	//���ջ�������ӿռ�
	if(s->top-s->base>=s->stacksize)
	{
		s->base=(int*)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(int));
		s->stacksize=s->stacksize+STACKINCREMENT;
	} 
	*(s->top)=e;
	s->top++;
}
