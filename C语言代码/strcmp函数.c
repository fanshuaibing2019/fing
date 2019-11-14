#include<stdio.h>
#include<string.h>
int mycmp(char const*s1,char const*s2)
{
	while(*s1==*s2 && *s1!='\0'){
		s1++;
		s2++;
	}
	return *s1-*s2;
}
int main(int argc,char const*argv[])
{
	char *s1="abc";//*s1->s1[]
	char *s2="Abc";//*s2->s2[]
	char *a1="abc";
	char *a2="Abc";
	printf("%d\n",mycmp/*strcmp*/(s1,s2));
	printf("%d\n",'A'-'a');
	printf("%d\n",strcmp(a1,a2));
	return 0;
}
