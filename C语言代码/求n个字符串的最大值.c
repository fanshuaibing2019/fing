#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n;
	printf("�ַ���������");
	scanf("%d",&n); 
	getchar(); 
	char str[20][20];
	char str1[20];
	printf("�������ַ�����\n");
	for(i=0;i<n;i++)
	{
		gets(str[i]);
	}
	strcpy(str1,str[0]);
	for(i=1;i<n;i++)
	{
		if(strcmp(str1,str[i])>0)
			continue;
		else 
			strcpy(str1,str[i]);
	} 
	printf("�����ַ���Ϊ\n%s\n",str1);
	return 0;
} 
