#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
 
typedef int Status;//将int定义为Status返回
typedef char Elemtype;//暂定Elemtype为char
 
//双向链表数据结构
typedef struct DualList
{
    Elemtype data;
    struct DualList *prior;
    struct DualList *next;
}DualNode,*DuaLinkList;//定义两个变量名，一个无指针，一个有指针
 
//初始化双向链表
Status Initlist(DuaLinkList *L)
{
    DualNode *p,*q;
    int i;
    //建立一个头节点指针
    (*L)=(DuaLinkList)malloc(sizeof(DualNode));
    //错误控制
    if (!(*L))
    {
        return ERROR;
    }
    //清零头节点
    (*L)->prior=(*L)->next=NULL;
    //这里使用p，q两个指针进行插入操作
    p=(*L);
    for (i=0;i<26;i++)
    {
        //建立一个节点指针
        q=(DuaLinkList)malloc(sizeof(DualNode));
        //错误控制
        if (!q)
        {
            return ERROR;
        }
        //以下操作进行节点的赋值与建立双向链表
        q->data='A'+i;
        q->next=p->next;
        q->prior=p;
        p->next=q;
        p=q;
 
    }
    //将最后一个结点链接回第一个结点，（注意，这里跳过头节点）建立循环链表
    p->next=(*L)->next;
    (*L)->next->prior=p;
    return OK;
 
}
//对双向循环链表的第一个结点与n进行同步操作
void caesar(DuaLinkList *L,int n)
{
    //假如n=0，此函数无法激活，即双向循环链表的第一个结点位置不变
    if (n>0)
    {
        //这里使用do while语句的原因是跳过头节点
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
    //初始化链表
    Initlist(&L);
    printf("请输入N值：\n");
    scanf("%d",&n);
    printf("\n");
    //变更初始结点的位置
    caesar(&L,n);
    
    for(i=0;i<26;i++)
    {
        
        L=L->next;//此步用于跳过头节点
        printf("%c",L->data);//输出打他值
    }
    return 0;
 
 
 
}

