#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#define size 20
#define stackincrement 10
typedef double elemtype;
typedef struct{
	elemtype *base;
	elemtype *top;
	int stacksize;
}sqstack;

void initstack(sqstack *s)
{
	s->base=(elemtype*)malloc(size*sizeof(elemtype));
	if(!s->base)exit(0);
	s->top=s->base;
	s->stacksize=size;
}
void push(sqstack *s,elemtype e)
{
	if(s->top-s->base>=s->stacksize)
	s->base=(elemtype*)realloc(s->base,(s->stacksize+stackincrement)*sizeof(elemtype));
	if(!s->base)exit(0);
	*(s->top)=e;
	s->top++;
}

void pop(sqstack *s,elemtype *e)
{
	if(s->top==s->base)return;
	*e=*--(s->top);
}



int main()
{
	sqstack s;
	char c;
	int i=0;
	double d,e;
	char str[stackincrement];
	initstack(&s);
	printf("�밴���沨�����ʽ������������ݣ������������֮���Կո������");
	scanf("%c",&c);
	while(c!='\n')
	{
		while(isdigit(c)||c=='.')
		{
			str[i++]=c;
			str[i]='\0';
			if(i>=10)printf("��������ĵ������ݹ���");
			scanf("%c",&c);
			if(c==' ')
			{
				d=atof(str);//���ַ���ת��Ϊ������ 
				push(&s,d);
				i=0;
				break;
			 } 
		}
		switch(c)
		{
			case '+':
				pop(&s,&d);
				pop(&s,&e);
				push(&s,d+e);
				break;
			case '-':
				pop(&s,&d);
				pop(&s,&e);
				push(&s,d+e);
				break;	
			case '*':
				pop(&s,&d);
				pop(&s,&e);
				push(&s,d*e);
				break;	
			case '/':
				pop(&s,&d);
				pop(&s,&e);
				if(e!=0)
					push(&s,d/e);
				else printf("\n����,����Ϊ0��"); 
				break;	
		}
		scanf("%c",&c);
	}
	pop(&s,&d);
	printf("\n���յļ�����%5.2f\n",d);
}
