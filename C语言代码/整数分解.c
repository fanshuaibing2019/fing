#include<stdio.h>
int main()
{
	int x,mask=1;
	scanf("%d",&x);
	int t=x;
	while(t>=10){
	
		t/=10;
		mask*=10;
    }
    int a;
	while(mask>=1){
		a=x/mask;
		x%=mask;
		mask/=10;
		printf("%d ",a); 
	}
	return 0;
 } 
