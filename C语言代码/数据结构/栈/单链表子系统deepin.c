#include<stdio.h>
#include<stdlib.h>
typedef struct linklist{
	char data;
	struct linklist *next;
}node;
node *head;
void creatlist()
{
	char x;
	int n=1,i=0;
	node *p,*q;
	head=(node*)malloc(sizeof(node));
	head->next=NULL;
	p=head;
	printf("\n请逐个输入字符，输入“x”结束。\n"); 
	while(n)
	{
		printf("\n请输入第%d结点字符:",++i);
		fflush(stdin);
		scanf("\n\t%c",&x);
		if(x!='x')
		{
			q=(node*)malloc(sizeof(node));
			q->data=x;
			q->next=NULL;
			p->next=q;
			p=q;
		}
		else n=0;
	}
}
void insertlist(int i,char x)
{
	node *p,*q;
	p=head;
	while(i--&&p->next!=NULL)
	{
		p=p->next;
	}
	if(p->next==NULL)
	{
		printf("\n结点不存在！\n");
	}
	else
	{
		q=(node*)malloc(sizeof(node));
		q->data=x;
		q->next=p->next;
		p->next=q;
		printf("\n\t插入成功！\n");
	}
}
void deletelist(char x)
{
	node *p,*q;
	p=head;
	q=head->next;
	while(q->data!=x&&q->next!=NULL)
	{
		p=q;
		q=q->next;
	}
	if(q->next==NULL)
	{
		printf("\n\t找不到数据!\n");
	}
	else if(q->data==x)
	{
		p->next=q->next;
		free(q);
	}
}
void showlist()
{
	node *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("\n%c",p->data);
		p=p->next;
	}
	if(head->next==NULL)
	{
		printf("\n该链表为空！\n");	
	}
}
void lengthlist()
{
	node *p;
	int i;
	p=head;
	for(i=0;p->next!=NULL;i++)
	{
		p=p->next;
	}
	printf("\n表长为%d\n",i);
	
}
void searchlist(int i)
{
	node *p;
	p=head;
	int n=i;
	while(i--&&p->next!=NULL)
	{
		p=p->next;
	}
	if(p->next!=NULL)
	{
		printf("\n第%d个数据为%c\n",n,p->data);
	}
	else
	{
		printf("\n结点不存在!\n");
	}
}
int main()
{
	int choice,i;
	char x;
	while(1)
	{
		printf("\n\t\t*****************\n");
		printf("\n\t\t*   1  建  表   *\n");
		printf("\n\t\t*   2  插  入   *\n");
		printf("\n\t\t*   3  删  除   *\n");
		printf("\n\t\t*   4  显  示   *\n");
		printf("\n\t\t*   5  求表长   *\n");
		printf("\n\t\t*   6  查  找   *\n");
		printf("\n\t\t*   0  退  出   *\n");
		printf("\n\t\t*****************\n");
		printf("\n请输入菜单号码:"); 
		scanf("%d",&choice);
		printf("\n");
		if(choice==1)
		{
			creatlist();
		}
		else if(choice==2)
		{
			printf("\n请输入插入位置(节点之后):");
			fflush(stdin); 
			scanf("%d",&i);
			printf("\n请输入字符:");
			fflush(stdin);
			scanf("%c",&x);
			insertlist(i,x); 
		}
		else if(choice==3)
		{
			printf("\n请输入删除数据:");
			fflush(stdin);
			scanf("%c",&x);
			deletelist(x);
		}
		else if(choice==4)
		{
			showlist();
		}
		else if(choice==5)
		{
			lengthlist();
		}
		else if(choice==6)
		{
			printf("\n请输入查找序号:");
			fflush(stdin);
			scanf("%d",&i);
			searchlist(i); 
		}
			
		else if(choice==0)break;
	}
	return 0; 
}
