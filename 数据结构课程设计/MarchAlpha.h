/************************************************************************************************************************
*												����ĸ��Ϸ���															*
*					      ��Ļ��������������ĸ���û������ϵ���Ӧ��ĸ�������ĸ��ʧ��									*
*																														*
*																														*
*																														*
*																														*
*																														*
*																														*
*																														*
*										���֪ʶ��		ͼ�β���������������ʱ�亯���ȡ�								*
*																														*
*										�ѵ㣺																			*
*										1.����API����ʵ���������������ĸ�Ĺ���											*
*										2.����API����ʵ�ֲ��뱳�����ֵĹ���												*
*										3.�ܹ�������������ֵ��ÿ���������ĸ����������Ϸ�ٶȵ�							*
*										4.�����ַ����ܺ������������������ü���س�										*
*										5.��δ�����Ϸ�Ѷ�																*
*																														*
*																						������ʼ���ڣ�11��8��			*
*																						�����������ڣ�					*
*																						�����ˣ�		�ſ� ��˧��				*
************************************************************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#include<time.h>
#pragma comment(lib,"winmm.lib")




//�����Ǻ�������
void out_meum();//��Ϸ�˵�����
void StartGame();//��ʼ��Ϸ������
void initGame(int* time, int* distance, int* level, int* life);

int AlphaLife(int time, int distance, int* score, int* life);//��ĸ����������
void showAlpha(char alpha);//��ʾ�ַ�������
char createAlpha();//�������һ����ĸ����
int dropAlpha(int x, int* y, char alpha, int time, int distance);//��ĸ�ĵ���
void flashScreen();//ˢ����Ļ
void Printframe(int distance);
void out_help();//��������
void about_Game();//������Ϸ
void QuitGame();//�˳���Ϸ
int MarchAlpha(char ch,char alpha);//ƥ����ĸ
