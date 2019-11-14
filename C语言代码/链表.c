#include<stdio.h>
struct student{
	int num;
	float score;
	struct student *next;
};
int main()
{
	struct student a,b,c,*head;
	a.num=10101;a.score=89.5;
	b.num=10103;b.score=90;
	c.num=10107;c.score=85;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	do{
		printf("%ld %5.1f\n",head->num,head->score);
		head=head->next;
	}while(head!=NULL);
	return 0;
}
