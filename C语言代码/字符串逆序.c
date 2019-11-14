#include<stdio.h>
#include<string.h>
void inverse(char *str)
{
	char*p1=str;
	char*p2=str+strlen(str)-1;
	while(p1<p2){
		char tmp=*p1;
		*p1=*p2;
		*p2=tmp;
		p1++;
		p2--;
	}
}
int main()
{
	char buf[10]="";
	scanf("%s",&buf);
	inverse(buf);
	printf("buf=%s\n",buf);
	return 0;
}
