#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	int i,j,k;
	int cnt=0;
	i=a;
	while(i<=a+3){
		j=a;
		while(j<=a+3){
			k=a;
			while(k<=a+3){
				if(i!=j){
					if(i!=k){
						if(j!=k){
							cnt++;
							printf("%d%d%d",i,j,k);
							if(cnt==6){
								cnt=0;
								printf("\n");
							}else{
								printf(" ");
							}
						}
					}
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
