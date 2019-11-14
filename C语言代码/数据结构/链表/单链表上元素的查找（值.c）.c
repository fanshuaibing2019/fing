typedef int elemtype;
typedef struct node{
	elemtype data;
	struct node *next;
}linklist; 

linklist *locade(linklist *head,elemtype x)
{
	linklist *p;
	p=head->next;
	while(p!=NULL&&p->!=x)
		p=p->next; 
	return p;
 
 } 
