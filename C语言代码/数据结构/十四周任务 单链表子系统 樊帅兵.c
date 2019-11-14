#include<stdio.h>
#include<stdlib.h>
typedef int elemtype; 
typedef struct node{
	elemtype data;
	struct node *next;
}linklist;
linklist *L;
linklist *creatlist(linklist *L)//链表初始化 
{
	linklist *p,*q;
	p=L;
	q=p;
	elemtype x;
	printf("\n输入元素(输入0结束):");
	scanf("%d",&x); 
	while(x!=0){
		p=(linklist*)malloc(sizeof(linklist));
		p->data=x;
		p->next=NULL;
		q->next=p;
		q=p;
		scanf("%d",&x);
	}printf("\n初始化成功!\n");
	return L;
 } 

linklist *reverselist(linklist *L)//链表逆序 
{
	linklist *p,*q,*s;
	p=L->next;
	q=NULL;
	L->next=NULL;
	while(p){
		s=p->next;
		p->next=q;
		q=p;
		p=s;
	}
	L->next=q;
	printf("\n操作成功!\n");
	printf("\n");
	return L; 
}

void isemty(linklist *L)//判断链表是否为空 
{
	if(L->next==NULL)printf("\n空链表\n");
	else printf("\n非空链表\n");
	printf("\n");
}

linklist *insertlist(linklist *L)//链表的插入 
{
	linklist *p,*s;
	int i;
	elemtype x; 
	printf("\n请输入所要插入的位置:\t");
	scanf("%d",&i);
	p=L;
	int j;
	for(j=1;j<i;j++)p=p->next;
	if(p){ 
		printf("请输入所要插入的值:\t");
		scanf("%d",&x);
		s=(linklist*)malloc(sizeof(linklist));
		s->data=x;
		s->next=p->next;
		p->next=s; 
		printf("\n插入成功!\n");
	}else printf("\n结点不存在,插入失败!\n");
	printf("\n");
	return L;
}

void lengthlist(linklist *L)//求表长 
{
	int len=0;
	linklist *p;
	p=L;
	while(p->next!=NULL){
		len++;
		p=p->next;
	}
	printf("\n该链表长度为%d\n",len);
	printf("\n");
}

linklist *find(linklist *L)//查询位置元素 
{
	linklist *p;
	int i,j;
	p=L;
	printf("\n请输入需要查找的元素位置:");
	scanf("%d",&i);
	for(j=0;j<i&&p!=NULL;j++)p=p->next;
	if(p==NULL)printf("\n第%d位不在范围内\n",j);
	else printf("\n第%d位置的元素为%d\n",j,p->data);
	printf("\n");
	return L;
}

linklist *locate(linklist *L)//查询元素位置 
{
	linklist *p;
	elemtype x;
	p=L->next;
	printf("\n请输入需要查找的元素:");
	scanf("%d",&x);
	int i=1;
	while(p!=NULL&&p->data!=x){
		p=p->next;
		i++;
	}
	if(p==NULL)printf("\n元素不存在!\n");
	else printf("\n该元素的位置为%d\n",i);
	printf("\n");
	return L;
}

linklist *deletelist(linklist *L)//链表的删除 
{
	linklist *p,*q;
	int i,j;
	p=L;
	printf("\n请输入删除结点位置:");
	scanf("%d",&i);
	for(j=1;j<i&&p!=NULL;j++)p=p->next;
	if(p->next==NULL)printf("\n结点不存在!\n");
	else{
		q=p->next;
		p->next=p->next->next;
		free(q);
		printf("\n删除成功!\n");
	}printf("\n");
	return L;
}

void printlist(linklist *L)//查看链表 
{
	linklist *p;
	p=L->next;
	if(p==NULL)printf("\n链表为空!\n");
	printf("\n");
	for(;p;p=p->next)printf("%d ",p->data);
	printf("\n");
}

void destorylist(linklist *L)//销毁链表 
{
	linklist *p,*q;
	p=L->next;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}L->next=NULL;
	printf("\n销毁成功!\n");
}

int main()
{
	int m;
	L=(linklist*)malloc(sizeof(linklist));
	L->next=NULL;
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
        printf("\n请输入所要达到第几号功能:");
        scanf("%d",&m);
        if(m==1)*creatlist(L);
        else if(m==2)*reverselist(L); 
        else if(m==3)isemty(L); 
        else if(m==4)*insertlist(L);
        else if(m==5)lengthlist(L); 
        else if(m==6)*find(L);
        else if(m==7)*locate(L); 
        else if(m==8)*deletelist(L);
        else if(m==9)printlist(L);
        else if(m==10)destorylist(L);
        else if(m==0)break;
        else printf("ERROR");
    }
    return 0;
}
