#include<stdio.h>
#include "student.h"
void getlist(student astu[],int number);
int save(student astu[],int number);
int main(int argc,char const*argv[])
{
	int number=0;
	printf("输入学生数量:");
	scanf("%d",&number);
	student astu[number];
	
	getlist(astu,number);
	if(save(astu,number)){
		printf("保存成功\n");
	}else printf("保存失败\n");
	return 0;
}
void getlist(student stu[],int number)
{
	char format[STR_LEN];
	sprintf(format,"%%%ds",STR_LEN-1);
	int i;
	for(i=0;i<number;i++){
		printf("第%d个学生:\n",i);
		printf("\t姓名：");
		scanf(format,astu[i].name);
		printf("\t性别(0-男，1-女，2-其他):");
		scanf("%d",&astu[i].genter);
		printf("\t年龄：");
		scanf("%d",&astu[i].age); 
	}
}
int save(student astu[],int number)
{
	int ret=-1;
	FILE*fp=fopen("student.date","w");
	if(fp){
		ret=fwrite(astu,sizeof(student),number,fp)
		fclose(tp);
	}
	return ret ==number;
}
