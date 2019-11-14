#include<stdio.h>
#include<string.h>
char *mycpy(char* dst,const char*src)
{
	int idx=0;
	while(idx!='\0'){
		dst[idx]=src[idx];
	}
	dst[idx]='\0';
	/*char*ret=dst;
	while(*dst++=*src++)
	;
	*dst='\0';
	return ret;
	*/
	return dst;
}
int main(int argc,char const *argv[])
{
	char s1[]="abc";
	char s2[]="abc";
	mycpy(s1,s2);
	return 0;
	
}
