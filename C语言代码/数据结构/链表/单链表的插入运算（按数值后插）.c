typedef int elemtype;
typedef struct node{
	elemtype data;
	struct node *next;
}linklist; 

void insert(linklist *head,elemtype x,elemtype k)//将x插入k之后
{
	linklist *p,*s,*q;
	s=(linklist*)malloc(sizeof(linklist));
	s->data=x;
	p=head->next;
	if(p==NULL){
		head->next=s;
		s->next=NULL;
	}
	else {
		q=head;
		while(p->data!=k)
		{
			q=p;
			p=p->next;
		}
		if(p!=NULL){
		s->next=p->next;
		p->next=s; 
	}
	else{
		q->next=s;
		s->next=NULL;
	}
} 
}
