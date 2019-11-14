#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,const char *argv[])
{
	char s[]="hello";
	char*a=s;
	char*p=strchr(a,'l');
	*p='\0';
	//char*t=(char*)malloc(strlen(s)+1);
	//strcpy(t,s);
	printf("%s\n",s);
	*p='l';
	//free(t);
	return 0;
 } 
