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
    	if(head->next==NULL) printf("������");
	else printf("�ǿ�����");
}

linklist *insertlist(linklist *head)//4
{
	linklist *p,*s;
	int i;
	int x; 
	printf("��������Ҫ�����λ�ã�\t");
	scanf("%d",&i);
	printf("��������Ҫ�����ֵ:\t");
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
     printf("�����Ա�ĳ���:  len= %d \n",len);
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
		printf("��������ȷ��λ�ã�%d��λ�ò��ڷ�Χ��\n", j);
		
	}
	else
	{
		printf("��%d��λ�õ�����Ϊ%d\n", j, p->data);
	}
}

void FindList(linklist *head)//7
{
	char x;
	int i=1;
	node *p;
	printf("\t\t��������Ҫ��ѯ��Ԫ��x:\t");
    scanf("%c",&x);
	if(head==NULL)
		printf("\t������ֻ��ͷָ�룡��");
	if(head->next==NULL)
		printf("\t�����Ա�Ϊ�գ�\n");
	p=head->next;
	while(p!=NULL&&(p->data!=x))
	{
		p=p->next;
		i++;
	}
	if(p!=NULL)
	{
		printf("\t\t������ĵ� %d λ�ҵ� x = %d \n",i,x);
	}

	else printf("\t\t�ڸ����Ա���û���ҵ�%d��\n",x);
}

linklist *deletelist(linklist *head)//8
{
	linklist *p,*q;
	int i,j;
	p=head;
	printf("������ɾ�����λ�ã�\t");
	scanf("%d",&i);
	for(j=1;j<i&&p!=NULL;j++)p=p->next;
	if(p->next==NULL)printf("��㲻����\n");
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
		printf("                              ���Ա���ϵͳ\n");
		printf("           ***************************************************\n");
		printf("           *               1---�����ʼ��                    *\n");
		printf("           *               2---��������                      *\n");
		printf("           *               3---�ж������Ƿ�Ϊ��              *\n");
		printf("           *               4---����Ĳ���                    *\n");
		printf("           *               5---���                        *\n");
		printf("           *               6---��ѯλ��Ԫ��                  *\n");
		printf("           *               7---��ѯԪ��λ��                  *\n");
		printf("           *               8---�����ɾ��                    *\n");
        printf("           *               9---�鿴����                      *\n");
        printf("           *               10---��������                     *\n");
        printf("           *               0---�˳�                          *\n");
        printf("           ***************************************************\n");
		printf("            �����루0-10��ѡ�\n");
        printf("\n��������Ҫ�ﵽ�ڼ��Ź��ܣ�\t");
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
            printf("������������������\n");
        }
    }
    return 0;
}

