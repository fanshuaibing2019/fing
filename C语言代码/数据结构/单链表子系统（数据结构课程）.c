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
	printf("\n����������ַ������롰x��������\n"); 
	while(n)
	{
		printf("\n�������%d����ַ�:",++i);
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
		printf("\n��㲻���ڣ�\n");
	}
	else
	{
		q=(node*)malloc(sizeof(node));
		q->data=x;
		q->next=p->next;
		p->next=q;
		printf("\n\t����ɹ���\n");
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
		printf("\n\t�Ҳ�������!\n");
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
		printf("\n������Ϊ�գ�\n");	
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
	printf("\n��Ϊ%d\n",i);
	
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
		printf("\n��%d������Ϊ%c\n",n,p->data);
	}
	else
	{
		printf("\n��㲻����!\n");
	}
}
int main()
{
	int choice,i;
	char x;
	while(1)
	{
		printf("\n\t\t*****************\n");
		printf("\n\t\t*   1  ��  ��   *\n");
		printf("\n\t\t*   2  ��  ��   *\n");
		printf("\n\t\t*   3  ɾ  ��   *\n");
		printf("\n\t\t*   4  ��  ʾ   *\n");
		printf("\n\t\t*   5  ���   *\n");
		printf("\n\t\t*   6  ��  ��   *\n");
		printf("\n\t\t*   0  ��  ��   *\n");
		printf("\n\t\t*****************\n");
		printf("\n������˵�����:"); 
		scanf("%d",&choice);
		printf("\n");
		if(choice==1)
		{
			creatlist();
		}
		else if(choice==2)
		{
			printf("\n���������λ��(�ڵ�֮��):");
			fflush(stdin); 
			scanf("%d",&i);
			printf("\n�������ַ�:");
			fflush(stdin);
			scanf("%c",&x);
			insertlist(i,x); 
		}
		else if(choice==3)
		{
			printf("\n������ɾ������:");
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
			printf("\n������������:");
			fflush(stdin);
			scanf("%d",&i);
			searchlist(i); 
		}
			
		else if(choice==0)break;
	}
	return 0; 
}
