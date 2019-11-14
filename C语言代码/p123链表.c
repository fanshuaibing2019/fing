#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	int value;
	struct _node *next;
}Node;
int main(int argc,char const *argv[])
{
	Node * head=NULL;
	int number;
	do{
		scanf("%d",&number);
		if(number!=-1){
			Node *p=(Node*)malloc(sizeof(Node));
			p->value=number;
			p->next=NULL;
			//Node *last=head;
			if(/*last*/head){
				while(last->next){
					last=last->next;
				}
				last->next=p;
			}else head=p;
		}
	}while(number!=-1);
	return 0;
 } 
