#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#define N sizeof(node)
typedef struct linknode
{    int data;
  struct linknode *next;
}node,linklist;
node *head;   

linklist *createlist(linklist *head,int n)//1
{
        linklist *p,*r;
        int i;
        srand(time(0));
        r=head;
        for(i=0;i<n;i++)
        {
                   p=(linklist*)malloc(N);
                   p->data=rand()%10;
                   p->next=NULL;
                   r->next=p;
                   r=p;
         }
          r->next=NULL;
          return head;
}

linklist *reverselist(linklist *head)//2
{			
    linklist *p,*q,*pr; 
    p = head->next; 
    q = NULL;  
    head->next = NULL; 
    while(p)
    {    
        pr = p->next;    
        p->next = q;    
        q = p;   
    	p = pr;  
    }  
    head->next = q;  
    return head;
}

void Listempty(linklist *head)//3
{
    	if(head->next==NULL) printf("空链表");
	else printf("非空链表");
}

linklist *insertlist(linklist *head)//4
{
	linklist *p,*s;
	int i;
	int x; 
	printf("请输入所要插入的位置：\t");
	scanf("%d",&i);
	printf("请输入所要插入的值:\t");
	scanf("%d",&x);
	p=head;
	int j;
	for(j=1;j<i;j++)p=head->next;
	s=(linklist*)malloc(N);
	s->data=x;
	s->next=p->next;
	p->next=s; 
	return head;
}

void LengthList(linklist *head)//5
{
int len=1;
linklist *p;
p=head->next;
while(p->next!=NULL)
     {
	p=p->next;
	len++;
     }
     printf("该线性表的长度:  len= %d \n",len);
}



void getlist(linklist *head, int j)//6
{
	linklist *p = head->next;
	int i = 1;
	while (p&&i < j){
		p = p->next;
		i++;
	}
	if (!p||i>j)
	{				
		printf("请输入正确的位置，%d该位置不在范围内\n", j);
		
	}
	else
	{
		printf("第%d个位置的数字为%d\n", j, p->data);
	}
}

void FindList(linklist *head)//7
{
	char x;
	int i=1;
	node *p;
	printf("\t\t请输入所要查询的元素x:\t");
    scanf("%c",&x);
	if(head==NULL)
		printf("\t该链表只有头指针！！");
	if(head->next==NULL)
		printf("\t该线性表为空！\n");
	p=head->next;
	while(p!=NULL&&(p->data!=x))
	{
		p=p->next;
		i++;
	}
	if(p!=NULL)
	{
		printf("\t\t在链表的第 %d 位找到 x = %d \n",i,x);
	}

	else printf("\t\t在该线性表中没有找到%d！\n",x);
}

linklist *deletelist(linklist *head)//8
{
	linklist *p,*q;
	int i,j;
	p=head;
	printf("请输入删除结点位置：\t");
	scanf("%d",&i);
	for(j=1;j<i&&p!=NULL;j++)p=p->next;
	if(p->next==NULL)printf("结点不存在\n");
	else{
		q=p->next;
		p->next=p->next->next;
		free(q);
	}
	return head;
}

void print(linklist *head)//9	
{
	linklist* p=head->next;
	while (p!=NULL)
	{
		printf("%d\n", p->data);
		p =p->next;
	}
}

void listdestory(linklist *head)//10
{
        linklist *q;
        while (head)
       {
                q=head->next;
                free(head);
                head=q;
       }
}

int main()
{
     char m;
    head=(linklist*)malloc(N);
	head->next=NULL;
    while(1)
    {
		printf("                              线性表子系统\n");
		printf("           ***************************************************\n");
		printf("           *               1---链表初始化                    *\n");
		printf("           *               2---链表逆序                      *\n");
		printf("           *               3---判断链表是否为空              *\n");
		printf("           *               4---链表的插入                    *\n");
		printf("           *               5---求表长                        *\n");
		printf("           *               6---查询位置元素                  *\n");
		printf("           *               7---查询元素位置                  *\n");
		printf("           *               8---链表的删除                    *\n");
        printf("           *               9---查看链表                      *\n");
        printf("           *               10---销毁链表                     *\n");
        printf("           *               0---退出                          *\n");
        printf("           ***************************************************\n");
		printf("            请输入（0-10）选项：\n");
        printf("\n请输入所要达到第几号功能：\t");
		scanf("%d",&m);
        if(m == 1)
            *createlist(head,5);
        else if(m == 2)
            *reverselist(head);
        else if(m == 3)
            Listempty(head);
        else if(m == 4)
            *insertlist(head);
        else if(m == 5)
            LengthList(head);
        else if(m == 6)
            getlist(head,3);
        else if(m == 7)
            FindList(head);
        else if(m == 8)
     		deletelist(head);
        else if(m == 9)
          	print(head);
         else if(m == 10)
         	listdestory(head);
         else if(m == 0)
        	break;
        else{
            printf("输入有误，请重新输入\n");
        }
    }
    return 0;
}

