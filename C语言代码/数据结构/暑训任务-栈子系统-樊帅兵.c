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

void initstack(sqstack *s)//1��ʼ�� 
{
	s->base=(elemtype*)malloc(size*sizeof(elemtype));
	if(!s->base)exit(0);
	s->top=s->base;
	s->stacksize=size;
	printf("\n��ʼ���ɹ�!\n"); 
}

void push(sqstack *s,elemtype x) //2��ջ 
{
	if(s->top-s->base>=s->stacksize)
	s->base=(elemtype*)realloc(s->base,(s->stacksize+stackincrement)*sizeof(elemtype));
	*s->top=x;
	s->top++;
}

elemtype pop(sqstack *s)//3��ջ 
{
	if(s->top==s->base)
	{
		printf("\n��ջ��\n");
		return;
	}
	--s->top;
	return *(s->top);
}

void lenstack(sqstack *s)//4ջ�� 
{
	printf("\nջ��Ϊ%d\n",s->top-s->base);
}

void showstack(sqstack *s)//5�鿴ջ 
{
	int i=0;
	if(s->top==s->base)printf("\n��ջ��\n");
	while(s->top!=s->base)
	{
		printf("%d ",*(--s->top));
		i++;
	}
	s->top+=i;
	printf("\n");
}

void clear(sqstack *s)//6���ջ 
{
	s->top=s->base;
	printf("\n�����ɹ�!\n");
}

void convert(sqstack *s)//7����ת�� 
{
	int n=0;
	printf("�ò��������ʼ��ջ���Ƿ������(0/1)");
	scanf("%d",&n);
	if(!n)return;
	initstack(s);
	int t,b;
	printf("\n������ʮ����������ת��Ϊ�Ľ��ƣ��ÿո������");
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

void destorystack(sqstack *s)//0����ջ 
{
	free(s->base);
	s->top=s->base=NULL;
	s->stacksize=0;
	printf("\n���ٳɹ�!\n");
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
		printf("                       ջ��ϵͳ\n");
		printf("***************************************************\n");
		printf("*               1------��ʼ��                     *\n");
		printf("*               2------��ջ                       *\n");
		printf("*               3------��ջ                       *\n");
		printf("*               4------ջ��                       *\n");
		printf("*               5------�鿴ջ                     *\n");
		printf("*               6------���ջ                     *\n");
		printf("*               7------����ת��                   *\n");
		printf("*               0------����ջ������               *\n");
		printf("***************************************************\n");
		printf("            ������0-7ִ��ѡ�\n");
        printf("\n��������Ҫ�ﵽ�ڼ��Ź��ܣ�\t");
		scanf("%d",&a);
        if(a == 1)
        	initstack(&s);
        else if(a == 2)
        {
        	elemtype x;
			printf("�������ݣ�");
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
        else printf("������������������!\n"); 
 }
}

