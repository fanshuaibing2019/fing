//#include<stdio.h>
//#include <stdlib.h>
//#include<conio.h>
//#include<windows.h>
//#include<mmsystem.h>
//#include<time.h>
//#pragma comment(lib,"winmm.lib")

#include "MarchAlpha.h"


//������������
int main()
{
	char* title = "����ĸ��Ϸ";
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
		about_Game();//������Ϸ
	}
	else if (Switch == 4)
	{
		QuitGame();//�˳���Ϸ
	}
	else
	{
		printf("ֵ������󣬳�������ֹ��\n");//�쳣����
	}
	system("pause");
	return 0;

}
