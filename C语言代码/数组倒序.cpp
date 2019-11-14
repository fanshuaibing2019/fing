#include<stdio.h>
int main(int argc,char const*argv[])
{void inv(int*x,int n);
	int i,a[10]={1,2,3,4,5,6,7,8,9,0};
	printf("The original array:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	inv(a,10);
	printf("The arry has been inverted:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
 } 
 void inv(int*x,int n)
 {
 	int temp,i,j=n-1,m=(n-1)/2;
 	for(i=0;i<=m;i++,j--){
 		temp=*(x+i);
 		*(x+i)=*(x+j);
 		*(x+j)=temp;
	 }
 }
/*void inv(int*x,int n)
{
	int *p,temp,*i,*j,m=(n-1)/2;
	i=x;j=x+n-1;p=x+m;
	for(;i<=p;i++,j--){
		temp=*i;*i=*j;*j=temp;
	}
}
*/

