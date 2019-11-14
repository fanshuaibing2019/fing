#include<stdio.h>
#define maxtreesize 100
typedef int elemtype;
typedef struct ptnode{
	elemtype data;//结点位置 
	int parent;//双亲位置 
}ptnode;

typedef struct{
	ptnode nodes[maxtreesize];
	int r;//根的位置
	int n;//结点位置 
}ptree; 
