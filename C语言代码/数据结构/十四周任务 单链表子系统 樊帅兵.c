#include<stdio.h>
#include<stdlib.h>
typedef int elemtype; 
typedef struct node{
	elemtype data;
	struct node *next;
}linklist;
linklist *L;
linklist *creatlist(linklist *L)//�����ʼ�� 
{
	linklist *p,*q;
	p=L;
	q=p;
	elemtype x;
	printf("\n����Ԫ��(����0����):");
	scanf("%d",&x); 
	while(x!=0){
		p=(linklist*)malloc(sizeof(linklist));
		p->data=x;
		p->next=NULL;
		q->next=p;
		q=p;
		scanf("%d",&x);
	}printf("\n��ʼ���ɹ�!\n");
	return L;
 } 

linklist *reverselist(linklist *L)//�������� 
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
	printf("\n�����ɹ�!\n");
	printf("\n");
	return L; 
}

void isemty(linklist *L)//�ж������Ƿ�Ϊ�� 
{
	if(L->next==NULL)printf("\n������\n");
	else printf("\n�ǿ�����\n");
	printf("\n");
}

linklist *insertlist(linklist *L)//����Ĳ��� 
{
	linklist *p,*s;
	int i;
	elemtype x; 
	printf("\n��������Ҫ�����λ��:\t");
	scanf("%d",&i);
	p=L;
	int j;
	for(j=1;j<i;j++)p=p->next;
	if(p){ 
		printf("��������Ҫ�����ֵ:\t");
		scanf("%d",&x);
		s=(linklist*)malloc(sizeof(linklist));
		s->data=x;
		s->next=p->next;
		p->next=s; 
		printf("\n����ɹ�!\n");
	}else printf("\n��㲻����,����ʧ��!\n");
	printf("\n");
	return L;
}

void lengthlist(linklist *L)//��� 
{
	int len=0;
	linklist *p;
	p=L;
	while(p->next!=NULL){
		len++;
		p=p->next;
	}
	printf("\n��������Ϊ%d\n",len);
	printf("\n");
}

linklist *find(linklist *L)//��ѯλ��Ԫ�� 
{
	linklist *p;
	int i,j;
	p=L;
	printf("\n��������Ҫ���ҵ�Ԫ��λ��:");
	scanf("%d",&i);
	for(j=0;j<i&&p!=NULL;j++)p=p->next;
	if(p==NULL)printf("\n��%dλ���ڷ�Χ��\n",j);
	else printf("\n��%dλ�õ�Ԫ��Ϊ%d\n",j,p->data);
	printf("\n");
	return L;
}

linklist *locate(linklist *L)//��ѯԪ��λ�� 
{
	linklist *p;
	elemtype x;
	p=L->next;
	printf("\n��������Ҫ���ҵ�Ԫ��:");
	scanf("%d",&x);
	int i=1;
	while(p!=NULL&&p->data!=x){
		p=p->next;
		i++;
	}
	if(p==NULL)printf("\nԪ�ز�����!\n");
	else printf("\n��Ԫ�ص�λ��Ϊ%d\n",i);
	printf("\n");
	return L;
}

linklist *deletelist(linklist *L)//�����ɾ�� 
{
	linklist *p,*q;
	int i,j;
	p=L;
	printf("\n������ɾ�����λ��:");
	scanf("%d",&i);
	for(j=1;j<i&&p!=NULL;j++)p=p->next;
	if(p->next==NULL)printf("\n��㲻����!\n");
	else{
		q=p->next;
		p->next=p->next->next;
		free(q);
		printf("\nɾ���ɹ�!\n");
	}printf("\n");
	return L;
}

void printlist(linklist *L)//�鿴���� 
{
	linklist *p;
	p=L->next;
	if(p==NULL)printf("\n����Ϊ��!\n");
	printf("\n");
	for(;p;p=p->next)printf("%d ",p->data);
	printf("\n");
}

void destorylist(linklist *L)//�������� 
{
	linklist *p,*q;
	p=L->next;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}L->next=NULL;
	printf("\n���ٳɹ�!\n");
}

int main()
{
	int m;
	L=(linklist*)malloc(sizeof(linklist));
	L->next=NULL;
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
        printf("\n��������Ҫ�ﵽ�ڼ��Ź���:");
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
