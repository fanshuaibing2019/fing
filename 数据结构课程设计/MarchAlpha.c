#include "MarchAlpha.h"


//�����Ǻ���ʵ��
void out_meum(int* Switch)
{
	int a=4;
	char c;
	while(1) 
	{
		flashScreen();
		printf("\t\t��ӭ�������ĸ��ϷС����\n\n");
		//mciSendString("open C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
		//mciSendString("play C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
		//printf("\t\t����Ϊ��Ϸ�˵���\n");
		printf("\t\t***********************************\n\n");
		gotoxy(30,4);
		printf("��ʼ��Ϸ\n\n");
		gotoxy(30,6);
		printf("��Ϸ����\n\n");
		gotoxy(30,8);
		printf("������Ϸ\n\n");
		gotoxy(30,10);
		printf("�˳���Ϸ\n\n");
		printf("\t\t***********************************\n");
		printf("\n\t\tͨ���������������ѡ��ģʽ���Ѷ�\n");
		gotoxy(26,a);
		printf("��");
		gotoxy(40,a);
		printf("��");
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
		printf("\n\n\t\t��ѡ����Ϸ�Ѷ�:  ");
		printf("< %d >\n",*level);
		printf("\n\n\t\tͨ���������������ѡ��ģʽ���Ѷ�\n\n\n\t\t����س�����ʼ��Ϸ��\n");
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
	default:*time = 2500; *distance = 25; *life = 20; printf("δ��ȷѡ���Ѷȣ�ϵͳ���Զ������Ѷ�Ϊ1��\n"); break;
	}
	Sleep(500);
	printf("\n\t\t�Ѷ�Level��%d", *level);
	Sleep(500);
	printf("\n\t\t��Ϸ��ʼ��......");
	Sleep(500);
	printf("\n\t\t��ʼ��ing......");
	Sleep(500);
	printf("\n\t\t��Ϸ��ʼ��");
	Sleep(500);
}

void StartGame()//��ʼ��Ϸ
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
	printf("\n\t\t����ֵ0��\n\n\t\t��Ϸ�������ĵ÷�Ϊ\t%d\n",score);
	return;
}

int AlphaLife(int *time, int distance,int *score,int *life)//һ����ĸ���������ڣ��Ӵ�������ʧ��
{	static int n=0;//��������10���� 
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
				printf("miss�� -1\n");
				(*life)--;
				//printf("\t\t����ֵ��һ!��ǰ����ֵ��%d\n", *life);
				return 0;
				//break;
			}

		}
		else
		{
			flashScreen();
			//�˴�дδ������ĸ��������ĸ����ĺ���
			if (dropAlpha(x, &y, alpha, time, distance,score,life) == 1)
			{
				(*life)--;
				gotoxy(30,distance-1);
				printf("miss�� -1\n");
				//printf("����ֵ��һ!��������ֵ��%d\n", *life);
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
	printf("%c\n", alpha);
}

int dropAlpha(int x, int *y, char alpha, int *time, int distance,int *score,int *life)//������ĸ
{
	if (*y<distance)
	{ 	
		gotoxy(x,*y);
		showAlpha(alpha);
		Printframe(distance);
		printf("\n\t\t\t���� %d\t\t����ֵ %d\n",*score,*life);
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


void flashScreen()//ˢ����Ļ
{
	system("cls");
}

void Printframe(int distance)//������ 
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

void out_help()//����
{
	flashScreen();
	printf("\n\
��ʼ��Ϸ����ѡ����Ϸ�Ѷȣ�������Ϸ������Ϸ�������Ϸŵ�����ĸ��\n\n\
�����Ҫ����ĸ���䵽�ײ�֮ǰͨ������������ĸƥ�䣬ƥ��ɹ����\n\n\
����һ����ĸ���䣬ʧ�����һ������ֵ��������ֵ��Ϊ0ʱ��Ϸ������\n\n\
ÿһ���Ѷ��ڽ�����Ϸһ��ʱ��󶼻��𽥼Ӵ�!\n\n����������أ�");
	getch();
	main();
}

void about_Game()//������Ϸ
{
	flashScreen(); 
	printf("\n\t\t��Ϸ���� �ſ� ��˧��\n\n\
\t\t��Ϸ��; ���ݽṹ�������\n\n\
\t\t�������� 2019��11��\n\n\
\t\tgithub\thttps://github.com/fanshuaibing2019/fing.git\n\n\t\t����������أ�\n"); 
	getch();
	main();
}

void QuitGame()//�˳���Ϸ
{
	flashScreen();
	printf("\n\t\t��Ϸ������\n");
	return;
}
