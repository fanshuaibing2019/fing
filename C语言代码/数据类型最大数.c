#include<stdio.h>
int main()
{int a=0,b=0;
while(++a>0);
printf("int��������������ǣ�%d\n",a-1);
while((a/=10)!=0)
{b++;
}
printf("int����������������λ����%d",b+1);
return 0;
} 
