#include<stdio.h>
#define maxtreesize 100
typedef int elemtype;
typedef struct ptnode{
	elemtype data;//���λ�� 
	int parent;//˫��λ�� 
}ptnode;

typedef struct{
	ptnode nodes[maxtreesize];
	int r;//����λ��
	int n;//���λ�� 
}ptree; 
