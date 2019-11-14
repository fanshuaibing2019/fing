#include<stdio.h>
float paixu(float a[]);
int main ()
{
	float a[5];
	int i;
	printf("ÇëÊäÈë5¸öÊı£º\n");
	for(i=0;i<5;i++)
		scanf("%f",&a[i]);
	paixu(a);
	for(i=0;i<5;i++)
		printf("%2.1f\n",a[i]);
		return 0;
}
float paixu(float a[])
{
	int i,j;
	float t=0.0;
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(a[j]<a[i]){
		        t= a[i];
		        a[i]=a[j];
		        a[j]=t;
      		}
		}
	}
}

