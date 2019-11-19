#include "MarchAlpha.h"


//�����Ǻ���ʵ��
void out_meum()
{

	printf("\t\t��ӭ�������ĸ��ϷС����\n");
	//mciSendString("open C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
	//mciSendString("play C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
	printf("\t\t����Ϊ��Ϸ�˵���\n");
	printf("\t\t***********************************\n");
	printf("\t\t**-----      1.��ʼ��Ϸ     -----**\n");
	printf("\t\t**-----      2.��Ϸ����     -----**\n");
	printf("\t\t**-----      3.���ڱ���Ϸ   -----**\n");
	printf("\t\t**-----      4.�˳���Ϸ     -----**\n");
	printf("\t\t***********************************\n");
	printf("\t\t��ѡ��Ҫִ�еĲ�����\t");
	return;
}

void initGame(int* time, int* distance, int* level,int *life)
{

	printf("\n\t\t��ѡ����Ϸ�Ѷ�(1~5)��\t");
	//scanf("%d",level);
	(char)(*level);
	*level=getche()-48;
	(int)(*level);
	//getchar();
	switch (*level)
	{
	case 1:*time = 1300; *distance = 25; *life = 20; break;
	case 2:*time = 1000; *distance = 20; *life = 18; break;
	case 3:*time = 700; *distance = 16; *life = 15; break;
	case 4:*time = 500; *distance = 12; *life = 12; break;
	case 5:*time = 300; *distance = 5; *life = 8; break;
	default:*time = 2500; *distance = 25; *life = 20; printf("δ��ȷѡ���Ѷȣ�ϵͳ���Զ������Ѷ�Ϊ1��\n"); break;
	}
	Sleep(500);
	printf("\n\t\t�Ѷ�Level��%d\t", *level);
	Sleep(500);
	printf("\n\t\t��Ϸ��ʼ��......\n");
	Sleep(500);
	printf("\n\t\t��ʼ��ing......\n");
	Sleep(500);
	printf("\n\t\t��Ϸ��ʼ��\n");
	Sleep(500);
}

void StartGame()//��ʼ��Ϸ
{
	int time = 0, distance = 0, level = 0, life = 0, score = 0;;
	initGame(&time, &distance, &level,&life);

	while (1)
	{
		AlphaLife(time, distance,&score,&life);
		if (life == 0)
		{
			break;
		}
	}
	flashScreen();
	printf("\n\t\t����ֵ0��\n\t\t��Ϸ�������ĵ÷�Ϊ\t%d\n",score);
	return;
}

int AlphaLife(int time, int distance,int *score,int *life)//һ����ĸ���������ڣ��Ӵ�������ʧ��
{
	char alpha = createAlpha();
	char ch;
	//*score = 0;
	int x=rand()%30,y = 0;
	//showAlpha(alpha);
	Sleep(time);
	while (1)
	{
		if (_kbhit())
		{
			ch=getch();
			//ch = getchar();
			//getchar();
			if (MarchAlpha(ch, alpha) == 1)
			{
				(*score)++;
				return 1;
				//break;
			}
			else
			{
				printf("\n\t\tmiss��\n");
				(*life)--;
				printf("\t\t����ֵ��һ!��ǰ����ֵ��%d\n", *life);
				return 0;
				//break;
			}

		}
		else
		{
			flashScreen();
			//�˴�дδ������ĸ��������ĸ����ĺ���
			if (dropAlpha(x, &y, alpha, time, distance) == 1)
			{
				(*life)--;
				printf("����ֵ��һ!��������ֵ��%d\n", *life);
				return 0;
				//break;
			}
		}
	}


}
char createAlpha()//������ĸ
{
	srand(time(0));
	return 'a'+rand()%26;
}

int MarchAlpha(char ch, char alpha)
{
	if (ch == alpha)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void gotoxy(int x,int y)
{
	COORD loc = {x,y};
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
}

void showAlpha(char alpha)//չʾ��ĸ
{
	printf("\t\t %c\n", alpha);
}

int dropAlpha(int x, int *y, char alpha, int time, int distance)//������ĸ
{
	if (*y<distance)
	{ 	
		gotoxy(x,*y);
		showAlpha(alpha);
		Printframe(distance);
		(*y)++;
		Sleep(time);

		
	}
	else if (distance==*y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void flashScreen()//ˢ����Ļ
{
	system("cls");
}

void Printframe(int distance)//������ 
{
	int i=0,n=30;
	gotoxy(0,0);
	printf("\t\t ");
	for(i=0;i<=n;i++)
	{
		printf("-");
	}
	for(i=0;i<distance-1;i++)
	{
		printf("\n\t\t|\t\t\t\t|");
	}
	gotoxy(0,distance);
	printf("\t\t ");
	for(i=0;i<=n;i++)
	{
		printf("-");
	}
}

void out_help()//����
{
	return;
}

void about_Game()//������Ϸ
{
	return;
}

void QuitGame()//�˳���Ϸ
{
	return;
}
