#include<stdio.h>
int main()
{
	char str[99];
	int count=0,i;
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' '&&str[i+1]==' ')
		{
			count++;
		}
	}
	if(str[i-1]==' ')
	{
		count--;
	}
	printf("%d",count+1);
	return 0;
} 
