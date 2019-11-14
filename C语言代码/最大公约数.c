#include<stdio.h>
int main()
{
	int x,y,min;
	scanf("%d %d",&x,&y);
	if(x>y){
		min=y;
	}else{
		min=x;
	 }
	int a,ret;
	for(a=1;a<=min;a++){
		if(x%a==0){
			if(y%a==0){
			   ret=a;
		    }
		}
	}
	printf("%d",ret);
	return 0;
 } 
