#include<stdio.h>
#include<string.h>
struct student{
	long num;
	char name[10];
	char sex;
	float score;
};

int main()
{struct student stu_1;
 struct student *p;
	p=&stu_1;
	stu_1.num=10101;
	strcpy(stu_1.name,"li lin");
	stu_1.sex='m';
	stu_1.score=89.5;
	printf("No.%ld\nname:%s\nsex:%c\nscore:%5.1f\n",
			stu_1.num,stu_1.name,stu_1.sex,stu_1.score);
	printf("No.%ld\nname:%s\nsex:%c\nscore:%5.1f\n",
			(*p).num,(*p).name,(*p).sex,(*p).score);//p->num,p->name,p->sex,p->score 
			return 0;
 } 
