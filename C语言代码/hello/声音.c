#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
int main()
{//https://blog.csdn.net/qq_41443987/article/details/80412942
	printf("hello world!\n");
	mciSendString("open C:\\Users\\·®Ë§±ø\\Desktop\\11111.mp3", NULL, 0, NULL);
	mciSendString("play C:\\Users\\·®Ë§±ø\\Desktop\\11111.mp3", NULL, 0, NULL);
	while (1);
	return 0;
}