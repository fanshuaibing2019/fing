#include<stdio.h>
#include "student.h"
void getlist(student astu[],int number);
int save(student astu[],int number);
int main(int argc,char const*argv[])
{
	int number=0;
	printf("����ѧ������:");
	scanf("%d",&number);
	student astu[number];
	
	getlist(astu,number);
	if(save(astu,number)){
		printf("����ɹ�\n");
	}else printf("����ʧ��\n");
	return 0;
}
void getlist(student stu[],int number)
{
	char format[STR_LEN];
	sprintf(format,"%%%ds",STR_LEN-1);
	int i;
	for(i=0;i<number;i++){
		printf("��%d��ѧ��:\n",i);
		printf("\t������");
		scanf(format,astu[i].name);
		printf("\t�Ա�(0-�У�1-Ů��2-����):");
		scanf("%d",&astu[i].genter);
		printf("\t���䣺");
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
