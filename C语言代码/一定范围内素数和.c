#include<stdio.h>
int main()
{
	int m,n;
	int i,sum=0,cnt=0;
	scanf("%d %d",&m,&n);
	if(m==1)m=2;
	for(i=m;i<=n;i++){
		int isprime=1,a;
		for(a=2;a<i;a++){
			if(i%a==0){
				isprime=0;
				break;
			}
		}
		if(isprime==1){
			cnt++;
			sum+=i;	
		}
	}printf("%d %d",cnt,sum);
	return 0;
}
