#include<stdio.h>
#include<stdlib.h>
#define elemtype int
typedef struct stack{
	elemtype data;
	struct stack *next;
}linkstack;
linkstack *top;
//��ʼ����
linkstack *inistack(linkstack *top)
{
	
	top=(linkstack*)malloc(sizeof(linkstack));
	if(top==NULL)
		exit(1);
	top->next=NULL;
	return top;
}


//��ջ��
void push(linkstack *top,elemtype x)
{
	linkstack *p;
	p=(linkstack*)malloc(sizeof(linkstack));
	p->data=x;
	p->next=top->next;
	top->next=p;
}


//��ջ
elemtype pop(linkstack *top)
{
	linkstack *p;
	elemtype x;
	p=top->next;
	if(p==NULL)
	{
		printf("ջ�ѿ�\n");
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

//ȡջ��Ԫ��
elemtype gettop(linkstack *top)
{
	if(top->next!=NULL)
		printf("%d\n",top->next->data);
	else
		return 0;
}


//�ж�ջ�Ƿ�Ϊ�� 
int empty(linkstack *top)
{
	if(top->next==NULL)
	{ 
		printf("��ջ\n"); 
		return 0; 
	}	
	else
	{
		printf("�ǿ�ջ\n"); 
		return 1;
	}
}




//����ת��
void convert()
{
	
	int n,b;
	top->next=NULL;
	printf("������ʮ������n���������b���ÿո����:");
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
		printf("                       ջ��ϵͳ\n");
		printf("***************************************************\n");
		printf("*               1------��    ջ                   *\n");
		printf("*               2------��    ջ                   *\n");
		printf("*               3------��ʾջ��Ԫ��               *\n");
		printf("*               4------�ж�ջ�Ƿ�Ϊ��             *\n");
		printf("*               5------����ת��                   *\n");
		printf("*               0------��    ��                   *\n");
		printf("***************************************************\n");
		printf("            �����루0-5��ѡ�\n");
        printf("\n��������Ҫ�ﵽ�ڼ��Ź��ܣ�\t");
		scanf("%d",&a);
        if(a == 1)
        {
        	elemtype x;
			printf("�����ջ���ݣ�");
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
        else printf("������������������!\n"); 
	
 } 
}
 
