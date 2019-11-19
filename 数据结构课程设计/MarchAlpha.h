/************************************************************************************************************************
*												打字母游戏设计															*
*					      屏幕随机产生下落的字母，敲击键盘上的相应字母键则该字母消失。									*
*																														*
*																														*
*																														*
*																														*
*																														*
*																														*
*																														*
*										相关知识：		图形操作、按键操作、时间函数等。								*
*																														*
*										难点：																			*
*										1.调用API函数实现随机产生下落字母的功能											*
*										2.调用API函数实现插入背景音乐的功能												*
*										3.能够自由设置生命值、每次下落的字母数、设置游戏速度等							*
*										4.输入字符后能后立即做出反馈而不用键入回车										*
*										5.如何处理游戏难度																*
*																														*
*																						制作开始日期：11月8日			*
*																						制作结束日期：					*
*																						制作人：		张凯 樊帅兵				*
************************************************************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#include<time.h>
#pragma comment(lib,"winmm.lib")




//以下是函数声明
void out_meum();//游戏菜单函数
void StartGame();//开始游戏主函数
void initGame(int* time, int* distance, int* level, int* life);

int AlphaLife(int time, int distance, int* score, int* life);//字母的生命周期
void showAlpha(char alpha);//显示字符主函数
char createAlpha();//随机创造一个字母函数
int dropAlpha(int x, int* y, char alpha, int time, int distance);//字母的掉落
void flashScreen();//刷新屏幕
void Printframe(int distance);
void out_help();//帮助函数
void about_Game();//关于游戏
void QuitGame();//退出游戏
int MarchAlpha(char ch,char alpha);//匹配字母
