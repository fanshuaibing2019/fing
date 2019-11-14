#include<stdio.h>
#include<stdlib.h>
#define elemtype int
#define size 20
#define stackincrement 10
typedef struct stack{
	elemtype *base;
	elemtype *top;
	int stacksize;
}sqstack; 

void initstack(sqstack *s)//1初始化 
{
	s->base=(elemtype*)malloc(size*sizeof(elemtype));
	if(!s->base)exit(0);
	s->top=s->base;
	s->stacksize=size;
	printf("\n初始化成功!\n"); 
}

void push(sqstack *s,elemtype x) //2入栈 
{
	if(s->top-s->base>=s->stacksize)
	s->base=(elemtype*)realloc(s->base,(s->stacksize+stackincrement)*sizeof(elemtype));
	*s->top=x;
	s->top++;
}

elemtype pop(sqstack *s)//3出栈 
{
	if(s->top==s->base)
	{
		printf("\n空栈！\n");
		return;
	}
	--s->top;
	return *(s->top);
}

void lenstack(sqstack *s)//4栈长 
{
	printf("\n栈长为%d\n",s->top-s->base);
}

void showstack(sqstack *s)//5查看栈 
{
	int i=0;
	if(s->top==s->base)printf("\n空栈！\n");
	while(s->top!=s->base)
	{
		printf("%d ",*(--s->top));
		i++;
	}
	s->top+=i;
	printf("\n");
}

void clear(sqstack *s)//6清空栈 
{
	s->top=s->base;
	printf("\n操作成功!\n");
}

void convert(sqstack *s)//7数制转换 
{
	int n=0;
	printf("该操作将会初始化栈，是否继续？(0/1)");
	scanf("%d",&n);
	if(!n)return;
	initstack(s);
	int t,b;
	printf("\n请输入十进制整数和转化为的进制，用空格隔开：");
	scanf("%d %d",&t,&b);
	
	while(t)
	{
		push(s,t%b);
		t/=b;
	}
	while(s->top!=s->base)
		printf("%d",pop(s));
		printf("\n");
}

void destorystack(sqstack *s)//0销毁栈 
{
	free(s->base);
	s->top=s->base=NULL;
	s->stacksize=0;
	printf("\n销毁成功!\n");
}
int main()
{
	int a;
	sqstack	s; 
	s.base=(elemtype*)malloc(size*sizeof(elemtype));
	s.top=s.base;
	s.stacksize=size;
	while(1)
    {
		printf("                       栈子系统\n");
		printf("***************************************************\n");
		printf("*               1------初始化                     *\n");
		printf("*               2------入栈                       *\n");
		printf("*               3------出栈                       *\n");
		printf("*               4------栈长                       *\n");
		printf("*               5------查看栈                     *\n");
		printf("*               6------清空栈                     *\n");
		printf("*               7------数制转换                   *\n");
		printf("*               0------销毁栈并返回               *\n");
		printf("***************************************************\n");
		printf("            请输入0-7执行选项：\n");
        printf("\n请输入所要达到第几号功能：\t");
		scanf("%d",&a);
        if(a == 1)
        	initstack(&s);
        else if(a == 2)
        {
        	elemtype x;
			printf("输入数据：");
			scanf("%d",&x);
            push(&s,x);
    	}
        else if(a == 3)
            pop(&s);
        else if(a == 4)
           lenstack(&s);
        else if(a == 5)
            showstack(&s);
        else if(a == 6)
            clear(&s);
        else if(a == 7)
        	convert(&s);
        else if(a == 0)
        { 
        	destorystack(&s);
            return 0;
        } 
        else printf("输入有误，请重新输入!\n"); 
 }
}

