#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
 
typedef int Status;//��int����ΪStatus����
typedef char Elemtype;//�ݶ�ElemtypeΪchar
 
//˫���������ݽṹ
typedef struct DualList
{
    Elemtype data;
    struct DualList *prior;
    struct DualList *next;
}DualNode,*DuaLinkList;//����������������һ����ָ�룬һ����ָ��
 
//��ʼ��˫������
Status Initlist(DuaLinkList *L)
{
    DualNode *p,*q;
    int i;
    //����һ��ͷ�ڵ�ָ��
    (*L)=(DuaLinkList)malloc(sizeof(DualNode));
    //�������
    if (!(*L))
    {
        return ERROR;
    }
    //����ͷ�ڵ�
    (*L)->prior=(*L)->next=NULL;
    //����ʹ��p��q����ָ����в������
    p=(*L);
    for (i=0;i<26;i++)
    {
        //����һ���ڵ�ָ��
        q=(DuaLinkList)malloc(sizeof(DualNode));
        //�������
        if (!q)
        {
            return ERROR;
        }
        //���²������нڵ�ĸ�ֵ�뽨��˫������
        q->data='A'+i;
        q->next=p->next;
        q->prior=p;
        p->next=q;
        p=q;
 
    }
    //�����һ��������ӻص�һ����㣬��ע�⣬��������ͷ�ڵ㣩����ѭ������
    p->next=(*L)->next;
    (*L)->next->prior=p;
    return OK;
 
}
//��˫��ѭ������ĵ�һ�������n����ͬ������
void caesar(DuaLinkList *L,int n)
{
    //����n=0���˺����޷������˫��ѭ������ĵ�һ�����λ�ò���
    if (n>0)
    {
        //����ʹ��do while����ԭ��������ͷ�ڵ�
        do
        {
            (*L)=(*L)->next;
        }while(--n);
 
    }
    if(n<0)
    {
        do
        {
            (*L)=(*L)->next;
        }while(++n);
    }
 
}
int main()
{
    DuaLinkList L;
    int n,i;
    //��ʼ������
    Initlist(&L);
    printf("������Nֵ��\n");
    scanf("%d",&n);
    printf("\n");
    //�����ʼ����λ��
    caesar(&L,n);
    
    for(i=0;i<26;i++)
    {
        
        L=L->next;//�˲���������ͷ�ڵ�
        printf("%c",L->data);//�������ֵ
    }
    return 0;
 
 
 
}

