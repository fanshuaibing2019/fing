#include<stdio.h>
#include<stdlib.h>
struct student
{
	char sname[20];//���� 
	int sno;//ѧ�� 
	char sgender[2];//�Ա� 
	struct student *next;////��һ����ַ 
};//����ṹ�� 
void input(struct student *L,int n)//���뺯�� 
{
	struct student *p,*s;//����ָ����� 
	s=L;//sָ��ԭ����L 
	int i=0; 
	while(i<n) //����ѭ������ 
	{
		p=(struct student *)malloc(sizeof(struct student));//�����µĽ�� 
		scanf("%s %d %s",&p->sname,&p->sno,&p->sgender);//����ڵ����� 
		s->next=p;//ʹs��nextָ��p�Ľ�� 
		s=p;//sָ��ָ��p�ĵ�ַ 
		i++;
	}
	s->next=NULL;//��βָ������ÿ� 
}
void output(struct student *L)//������� 
{
	struct student *p=L->next;//����ָ��ָ��ԭ�����next��ַ 
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
	L=(struct student *)malloc(sizeof(struct student));//�������� 
	scanf("%d",&t);
	input(L,t);
	output(L);
	return 0;
}


