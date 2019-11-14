#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 20
#define stackincrement 10
typedef char elemtype;
typedef struct{
	elemtype *base;
	elemtype *top;
	int stacksize;
}sqstack;

void initstack(sqstack *s)//��ʼ�� 
{
	s->base=(elemtype *)malloc(size*sizeof(elemtype));
	if(!s->base)exit(0);
	s->top=s->base;
	s->stacksize=size;
}

void push(sqstack *s,elemtype e)
{
	if(s->top-s->base>=s->stacksize)
	s->base=(elemtype *)realloc(s->base,(s->stacksize+stackincrement)*sizeof(elemtype));
	if(!s->base)exit(0);
	*(s->top)=e;
	s->top++;
 } 
 
 void pop(sqstack *s,elemtype *e)
 {
 	if(s->top==s->base)return;
 	*e=*--s->top;
 }
 
 int stacklen(sqstack s)
 {
 	return(s.top-s.base);
 }
 
 int main()
 {
 	elemtype c;
 	sqstack a;
 	initstack(&a);
 	int len,i,sum=0;
 	printf("�������������:\n");
 	scanf("%c",&c);
 	while(c!='\n')
 	{
 		push(&a,c);
 		scanf("%c",&c);
	}
	
	len=stacklen(a);
	printf("ջ�ĵ�ǰ����Ϊ%d\n",len);
	for(i=0;i<len;i++)
	{
		pop(&a,&c);
		sum+=(c-48)*pow(2,i);
	}
	 printf("%d\n",sum);
 	return 0;
 }
