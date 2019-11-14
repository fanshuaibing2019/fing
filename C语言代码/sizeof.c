#include<stdio.h>
int main()
{
int a=6;
printf("sizeof(a)=%ld\n",sizeof(a++));
printf("sizeof(long double)=%ld\n",sizeof(long double));
printf("a=%d\n",a);
return 0; 
} 
