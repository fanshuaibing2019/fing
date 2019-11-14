#include<stdio.h>
int main()
{
	int n,m,i=0,a[8];
	scanf("%d %d",&n,&m);
	while(n!=0){
		a[i]=n%m;
		n/=m;
		i++;
	}
	for(i=i-1;i>=0;i--){
		if(a[i]==10)printf("A");
		else if(a[i]==11)printf("B");
		else if(a[i]==12)printf("C");
		else if(a[i]==13)printf("D");
		else if(a[i]==14)printf("E");
		else if(a[i]==15)printf("F");
		else printf("%d",a[i]);
	}
	return 0;
} 
