#include<stdio.h>
int main()
{	void average(float*p,int n);
	void search(float(*p)[4],int n);
	float score[3][4]={65,67,70,60, 
						80,87,90,81,
						90,99,100,98};
	average(score[0],12);
	search(score,2);//求序列为2的学生的成绩
	return 0; 
}
void average(float*p,int n)
{
	float sum=0,aver,*i;
	i=p+n;
	for(;p<i;p++)
		sum+=*p;
		aver=sum/n;
		printf("averager=%5.2f\n",aver);
}
void search(float(*p)[4],int n)
{
	int i;
	for(i=0;i<4;i++)
		printf("%5.2f ",*(p[n]+i));
	printf("\n");
}
