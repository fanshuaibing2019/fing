#include<stdio.h>
#include<stdlib.h>
struct student
{
	char sname[20];//姓名 
	int sno;//学号 
	char sgender[2];//性别 
	struct student *next;////下一结点地址 
};//定义结构体 
void input(struct student *L,int n)//输入函数 
{
	struct student *p,*s;//定义指针变量 
	s=L;//s指向原链表L 
	int i=0; 
	while(i<n) //控制循环次数 
	{
		p=(struct student *)malloc(sizeof(struct student));//生成新的结点 
		scanf("%s %d %s",&p->sname,&p->sno,&p->sgender);//输入节点内容 
		s->next=p;//使s的next指向p的结点 
		s=p;//s指针指向p的地址 
		i++;
	}
	s->next=NULL;//表尾指针变量置空 
}
void output(struct student *L)//输出函数 
{
	struct student *p=L->next;//定义指针指向原链表的next地址 
    while(p!=NULL)
    {
        printf("%s\t%d\t%s\n",p->sname,p->sno,p->sgender);
        p=p->next;
    }printf("\n");
}
int main()
{
	int t;
	struct student *L;
	L=(struct student *)malloc(sizeof(struct student));//生成链表 
	scanf("%d",&t);
	input(L,t);
	output(L);
	return 0;
}


