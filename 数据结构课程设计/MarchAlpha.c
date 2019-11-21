#include "MarchAlpha.h"


//以下是函数实现
void out_meum(int* Switch)
{
	int a=4;
	char c;
	while(1) 
	{
		flashScreen();
		printf("\t\t欢迎游玩打字母游戏小程序！\n\n");
		//mciSendString("open C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
		//mciSendString("play C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
		//printf("\t\t以下为游戏菜单：\n");
		printf("\t\t***********************************\n\n");
		gotoxy(30,4);
		printf("开始游戏\n\n");
		gotoxy(30,6);
		printf("游戏帮助\n\n");
		gotoxy(30,8);
		printf("关于游戏\n\n");
		gotoxy(30,10);
		printf("退出游戏\n\n");
		printf("\t\t***********************************\n");
		printf("\n\t\t通过方向键↑↓←→选择模式与难度\n");
		gotoxy(26,a);
		printf("→");
		gotoxy(40,a);
		printf("←");
		c=getch();
		if(c==80)
		{
			a+=2;
			(*Switch)++;
			if(a==12)
			{
				a=4;
				(*Switch)=1;
			}
		}
		else if(c==72)
		{
			a-=2;
			(*Switch)--;
			if(a==2)
			{
				a=10;
				(*Switch)=4;
			}
		}
		else if(c==13)
			break;
	}
}

void initGame(int* time, int* distance, int* level,int *life)
{
	int c;
	gotoxy(0,16);
	while(1)
	{
		flashScreen();
		printf("\n\n\t\t请选择游戏难度:  ");
		printf("< %d >\n",*level);
		printf("\n\n\t\t通过方向键↑↓←→选择模式与难度\n\n\n\t\t点击回车键开始游戏！\n");
		c=getch();
		if(c==75)
		{
			(*level)--;
			if(*level==0)(*level)=5;
			continue;
		}
		if(c==77)
		{
			(*level)++;
			if(*level==6)(*level)=1;
			continue;
		}
		if(c==13)
			break;
	}
	//scanf("%d",level);
//	(char)(*level);
//	*level=getche()-48;
//	(int)(*level);
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
	printf("\n\t\t难度Level：%d", *level);
	Sleep(500);
	printf("\n\t\t游戏初始化......");
	Sleep(500);
	printf("\n\t\t初始化ing......");
	Sleep(500);
	printf("\n\t\t游戏开始！");
	Sleep(500);
}

void StartGame()//开始游戏
{
	int time = 0, distance = 0, level = 1, life = 0, score = 0;;
	initGame(&time, &distance, &level,&life);

	while (1)
	{
		AlphaLife(&time, distance,&score,&life);
		if (life == 0)
		{
			break;
		}
	}
	flashScreen();
	printf("\n\t\t生命值0！\n\n\t\t游戏结束您的得分为\t%d\n",score);
	return;
}

int AlphaLife(int *time, int distance,int *score,int *life)//一个字母的生命周期（从创建到消失）
{	static int n=0;//计数，满10加速 
	char alpha = createAlpha();
	char ch;
	//*score = 0;
	int x=rand()%30+20,y = 0;
	//showAlpha(alpha);
	Sleep(*time);
	while (1)
	{
		if (_kbhit())
		{
			ch=getch();
			//ch = getchar();
			//getchar();
			if(MarchAlpha(ch, alpha) == 1)
			{
				(*score)++;
				n++;
				if(n==6)
				{
					n=0;
					(*time)*=0.8;
					(int)(*time);
				} 
				return 1;
				//break;
			}
			else
			{
				gotoxy(30,distance-1);
				printf("miss！ -1\n");
				(*life)--;
				//printf("\t\t生命值减一!当前生命值：%d\n", *life);
				return 0;
				//break;
			}

		}
		else
		{
			flashScreen();
			//此处写未键入字母，任由字母下落的函数
			if (dropAlpha(x, &y, alpha, time, distance,score,life) == 1)
			{
				(*life)--;
				gotoxy(30,distance-1);
				printf("miss！ -1\n");
				//printf("生命值减一!现在生命值：%d\n", *life);
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
	printf("%c\n", alpha);
}

int dropAlpha(int x, int *y, char alpha, int *time, int distance,int *score,int *life)//下落字母
{
	if (*y<distance)
	{ 	
		gotoxy(x,*y);
		showAlpha(alpha);
		Printframe(distance);
		printf("\n\t\t\t分数 %d\t\t生命值 %d\n",*score,*life);
		(*y)++;
		Sleep(*time);

		
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
	gotoxy(20,0);
	for(i=0;i<=n;i++)
	{
		printf("-");
	}
//	for(i=0;i<distance-1;i++)
//	{
//		printf("\n\t\t|\t\t\t\t|");
//	}
	gotoxy(20,distance);
	for(i=0;i<=n;i++)
	{
		printf("-");
	}
}

void out_help()//帮助
{
	flashScreen();
	printf("\n\
开始游戏可以选择游戏难度，进入游戏后在游戏区域会从上放掉落字母，\n\n\
玩家需要在字母掉落到底部之前通过键盘输入字母匹配，匹配成功则进\n\n\
行下一个字母掉落，失败则减一个生命值！当生命值降为0时游戏结束！\n\n\
每一种难度在进行游戏一段时间后都会逐渐加大!\n\n按任意键返回！");
	getch();
	main();
}

void about_Game()//关于游戏
{
	flashScreen(); 
	printf("\n\t\t游戏制作 张凯 樊帅兵\n\n\
\t\t游戏用途 数据结构程序设计\n\n\
\t\t开发日期 2019年11月\n\n\
\t\tgithub\thttps://github.com/fanshuaibing2019/fing.git\n\n\t\t按任意键返回！\n"); 
	getch();
	main();
}

void QuitGame()//退出游戏
{
	flashScreen();
	printf("\n\t\t游戏结束！\n");
	return;
}
