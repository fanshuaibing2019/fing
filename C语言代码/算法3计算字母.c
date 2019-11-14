#include<stdio.h>
int main()
{
	char str[99];
	int count=0,i,word=0;
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
		{
			word=0;
		}
		else if(str[i]!=' '&&word==0)
		{
			count++;
			word=1; 
		}
	}
	printf("%d",count);
	return 0;
} 
