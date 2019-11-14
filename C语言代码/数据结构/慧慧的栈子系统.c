#include<stdio.h>
#include<stdlib.h>
#define elemtype int
typedef struct stack{
	elemtype data;
	struct stack *next;
}linkstack;
linkstack *top;
//初始化：
linkstack *inistack(linkstack *top)
{
	
	top=(linkstack*)malloc(sizeof(linkstack));
	if(top==NULL)
		exit(1);
	top->next=NULL;
	return top;
}


//进栈：
void push(linkstack *top,elemtype x)
{
	linkstack *p;
	p=(linkstack*)malloc(sizeof(linkstack));
	p->data=x;
	p->next=top->next;
	top->next=p;
}


//出栈
elemtype pop(linkstack *top)
{
	linkstack *p;
	elemtype x;
	p=top->next;
	if(p==NULL)
	{
		printf("栈已空\n");
		return 0;
	}
	else
	{
		top->next=p->next;
		x=p->data;
		free(p);
		return(x);
	}
}

//取栈顶元素
elemtype gettop(linkstack *top)
{
	if(top->next!=NULL)
		printf("%d\n",top->next->data);
	else
		return 0;
}


//判断栈是否为空 
int empty(linkstack *top)
{
	if(top->next==NULL)
	{ 
		printf("空栈\n"); 
		return 0; 
	}	
	else
	{
		printf("非空栈\n"); 
		return 1;
	}
}




//数制转换
void convert()
{
	
	int n,b;
	top->next=NULL;
	printf("请输入十进制数n和输出进制b，用空格隔开:");
	scanf("%d %d",&n,&b);
	while(n)
	{
		push(top,n%b);
		n=n/b;
	}
	while(top->next!=NULL)
		printf("%d",pop(top));
		printf("\n");
}

int main()
{
	int a;
	top=(linkstack*)malloc(sizeof(linkstack));
	if(top==NULL)
		exit(1);
	top->next=NULL;
	
	while(1)
    {
		printf("                       栈子系统\n");
		printf("***************************************************\n");
		printf("*               1------进    栈                   *\n");
		printf("*               2------出    栈                   *\n");
		printf("*               3------显示栈顶元素               *\n");
		printf("*               4------判断栈是否为空             *\n");
		printf("*               5------数制转换                   *\n");
		printf("*               0------返    回                   *\n");
		printf("***************************************************\n");
		printf("            请输入（0-5）选项：\n");
        printf("\n请输入所要达到第几号功能：\t");
		scanf("%d",&a);
        if(a == 1)
        {
        	elemtype x;
			printf("输入进栈数据：");
			scanf("%d",&x);
            push(top,x);
    	}
        else if(a == 2)
            pop(top);
        else if(a == 3)
            gettop(top);
        else if(a == 4)
           empty(top);
        else if(a == 5)
            convert();
        else if(a == 0)
            return 0;
        else printf("输入有误，请重新输入!\n"); 
	
 } 
}
 
