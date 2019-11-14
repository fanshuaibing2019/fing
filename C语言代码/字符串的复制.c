#include<stdio.h>/*
int main()
{void copy_string(char from[],char to[]);
	char a[]="I am a teacher.";
	char b[]="You are a student.";
	printf("string a=%s\n",a);
	printf("string b=%s\n",b);
	copy_string(a,b);
	printf("copy string a to b\n");
	printf("string a=%s\n",a);
	printf("string b=%s\n",b);
	return 0;
}
void copy_string(char from[],char to[])
{
	int i;
	for(i=0;from[i]!='\0';i++)
		to[i]=from[i];
	to[i]='\0';
 } */
 int main()
 {void copy_string(char from[],char to[]);
 	char a[]="I am a teacher.";
	char b[]="You are a student.";
	char *from=a,*to=b;
	printf("string a=%s\n",a);
	printf("string b=%s\n",b);
	copy_string(from,to);
	printf("copy string a to b\n");
	printf("string a=%s\n",a);
	printf("string b=%s\n",b);
	return 0;
 }
 void copy_string(char from[],char to[])
 {
 	/*int i;
	for(i=0;from[i]!='\0';i++)
		to[i]=from[i];
	to[i]='\0';
	*/
	
	/*for(;*from!='\0';from++,to++)
		*to=*from;
		*to='\0';
	*/
	
	/*while((*to=*from)!='\0'){
		from++;
		to++;
	}
	//最后一次赋值为*to='\0';
	*/
	while((*to++=*from++)!='\0');
 }
 
