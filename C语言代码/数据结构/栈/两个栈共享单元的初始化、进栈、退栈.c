#include<stdio.h>
#define m 100//maxlen
typedef int elemtype;
typedef struct{
	elemtype stack[m];
	int top[2];
}duseqstack;
duseqstack *s;
void inistack(duseqstack *s)
{
	s->top[0]=-1;
	s->top[1]=m;
}
int push(duseqstack *s,elemtype x,int i)//使元素x进入以s栈空间的第i个栈中 
{
	if(s->top[0]==s->top[1]-1)
	{
		printf("overflow");
		return 0;
	}
	if(i!=0||i!=1)
	{
		printf("栈参数出错\n");
		return 0;
	}
	if(i==0)
	{
		s->top[0]++;
		s->stack[s->top[0]]=x;
	}
	else
	{
		s->top[1]--;
		s->stack[s->top[1]]=x;
	}
	return 0;
}
int pop(duseqstack *s,int i)//对以s为栈空间的栈中第i个栈进行退栈
{
	if(i!=0||i!=1)
	{
		printf("栈参数出错\n");
		return 0;
	}
	if(i==0)
	{
		if(s->top[0]==-1)
		{
			printf("0号栈已为空");
			return 0;
		}
		else
		{
			s->top[0]--;
			return (s->stack[s->top[0]+1]);
		}
	}
	else if(s->top[1]==m)
	{
		printf("1号栈已空");
		return 0; 
	}
	else
	{
		s->top[1]++;
		return (s->stack[s->top[1]-1]);
	}
}
