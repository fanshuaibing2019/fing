#include<stdio.h>
#include<string.h>

void StrMax()
{
	int n = 0;
	int i = 0;
	char str[100][80];
	char MaxString[] = "";
	printf("请输入要求字符串的组数！\n");
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		printf("请输入第%d组数据：\t", i + 1);
		gets(str[i]);
		if (strcmp(str[i], MaxString) > 0) /*若str[i]比MaxString大则替换MaxString*/
		{
			strcpy(MaxString, str[i]);
		}
		i++;
	}
	printf("最长的字符串为：\t");
	puts(MaxString);
	printf("\n");
	return;
}

void StrSort()
{
	int n = 0;
	int i = 0, j = 0;
	char tmp[200];
	char str[100][80];
	printf("请输入字符串组数！\n");
	scanf("%d", &n);
	getchar();

	while (n--)
	{
		printf("请输入第%d组数据：\t", i + 1);
		gets(str[i]);
		i++;
	}
	n = i;
	//getchar();
	for (i = 0; i < n; i++)
	{
		for (j = 0 ; j < n-i-1 ; j++)
		{
			if (strcmp(str[j], str[j + 1]) > 0)
			{
				strcpy(tmp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j+ 1], tmp);
			}
			
		}
		//printf("str[%d]为：\t%s\n", i, str[i]);
	}

	for (i = 0; i < n ; i++)
	{
		printf("第%d个字符串为\t",i + 1);
		puts(str[i]);
		printf("\n");
	}
}

int main(void)
{
	int tmp = 0;
	printf("请输入要执行的操作！\n1.求字符串最大值\t\t2.对n个字符串排序\n");
	scanf("%d", &tmp);
	if (tmp == 1)
	{
		StrMax();
	}
	else if (tmp == 2)
	{
		StrSort();
	}
	else
	{
		printf("输入了错误的序号！执行失败！");
	}


	return 0;
}

