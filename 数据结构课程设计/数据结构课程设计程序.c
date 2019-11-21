//#include<stdio.h>
//#include <stdlib.h>
//#include<conio.h>
//#include<windows.h>
//#include<mmsystem.h>
//#include<time.h>
//#pragma comment(lib,"winmm.lib")

#include "MarchAlpha.h"


//以下是主函数
int main()
{
	char* title = "打字母游戏";
	SetConsoleTitle(title);
	
	int Switch = 1;
	out_meum(&Switch);
	//scanf("%d", &Switch);
	//getchar();
//	(char)Switch;
//	Switch=getche()-48;
//	(int)Switch;
	if (Switch == 1)
	{
		StartGame();
	}
	else if(Switch == 2)
	{
		out_help();
	}

	else if(Switch == 3)
	{
		about_Game();//关于游戏
	}
	else if (Switch == 4)
	{
		QuitGame();//退出游戏
	}
	else
	{
		printf("值输入错误，程序已终止。\n");//异常处理
	}
	system("pause");
	return 0;

}
