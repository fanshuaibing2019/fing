#include<stdio.h>
#include<string.h>

void StrMax()
{
	int n = 0;
	int i = 0;
	char str[100][80];
	char MaxString[] = "";
	printf("������Ҫ���ַ�����������\n");
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		printf("�������%d�����ݣ�\t", i + 1);
		gets(str[i]);
		if (strcmp(str[i], MaxString) > 0) /*��str[i]��MaxString�����滻MaxString*/
		{
			strcpy(MaxString, str[i]);
		}
		i++;
	}
	printf("����ַ���Ϊ��\t");
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
	printf("�������ַ���������\n");
	scanf("%d", &n);
	getchar();

	while (n--)
	{
		printf("�������%d�����ݣ�\t", i + 1);
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
		//printf("str[%d]Ϊ��\t%s\n", i, str[i]);
	}

	for (i = 0; i < n ; i++)
	{
		printf("��%d���ַ���Ϊ\t",i + 1);
		puts(str[i]);
		printf("\n");
	}
}

int main(void)
{
	int tmp = 0;
	printf("������Ҫִ�еĲ�����\n1.���ַ������ֵ\t\t2.��n���ַ�������\n");
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
		printf("�����˴������ţ�ִ��ʧ�ܣ�");
	}


	return 0;
}

