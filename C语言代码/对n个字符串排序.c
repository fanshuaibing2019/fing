#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n;
	printf("×Ö·û´®ÊıÁ¿£º");
	scanf("%d",&n); 
	getchar(); 
	char str[20][80];
	char str1[80];
	printf("ÇëÊäÈë×Ö·û´®:\n");
	for(i=0;i<n;i++)
	{
		gets(str[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(strcmp(str[j],str[j+1])>=0)
			{
				strcpy(str1,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],str1);
			}
		}
	}
	printf("×Ö·û´®ÅÅĞòÎª\n"); 
	for(i=0;i<n;i++)
	{
		printf("%s ",str[i]);
	}
	return 0; 
}
