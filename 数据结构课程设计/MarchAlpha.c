#include "MarchAlpha.h"


//以下是函数实现
void out_meum()
{

	printf("\t\t欢迎游玩打字母游戏小程序！\n");
	//mciSendString("open C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
	//mciSendString("play C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
	printf("\t\t以下为游戏菜单：\n");
	printf("\t\t***********************************\n");
	printf("\t\t**-----      1.开始游戏     -----**\n");
	printf("\t\t**-----      2.游戏帮助     -----**\n");
	printf("\t\t**-----      3.关于本游戏   -----**\n");
	printf("\t\t**-----      4.退出游戏     -----**\n");
	printf("\t\t***********************************\n");
	printf("\t\t请选择要执行的操作：\t");
	return;
}

void initGame(int* time, int* distance, int* level,int *life)
{

	printf("\n\t\t请选择游戏难度(1~5)：\t");
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
	default:*time = 2500; *distance = 25; *life = 20; printf("未正确选择难度，系统将自动设置难度为1！\n"); break;
	}
	Sleep(500);
	printf("\n\t\t难度Level：%d\t", *level);
	Sleep(500);
	printf("\n\t\t游戏初始化......\n");
	Sleep(500);
	printf("\n\t\t初始化ing......\n");
	Sleep(500);
	printf("\n\t\t游戏开始！\n");
	Sleep(500);
}

void StartGame()//开始游戏
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
	printf("\n\t\t生命值0！\n\t\t游戏结束您的得分为\t%d\n",score);
	return;
}

int AlphaLife(int time, int distance,int *score,int *life)//一个字母的生命周期（从创建到消失）
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
				printf("\n\t\tmiss！\n");
				(*life)--;
				printf("\t\t生命值减一!当前生命值：%d\n", *life);
				return 0;
				//break;
			}

		}
		else
		{
			flashScreen();
			//此处写未键入字母，任由字母下落的函数
			if (dropAlpha(x, &y, alpha, time, distance) == 1)
			{
				(*life)--;
				printf("生命值减一!现在生命值：%d\n", *life);
				return 0;
				//break;
			}
		}
	}


}
char createAlpha()//创造字母
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

void showAlpha(char alpha)//展示字母
{
	printf("\t\t %c\n", alpha);
}

int dropAlpha(int x, int *y, char alpha, int time, int distance)//下落字母
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


void flashScreen()//刷新屏幕
{
	system("cls");
}

void Printframe(int distance)//输出框架 
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

void out_help()//帮助
{
	return;
}

void about_Game()//关于游戏
{
	return;
}

void QuitGame()//退出游戏
{
	return;
}
