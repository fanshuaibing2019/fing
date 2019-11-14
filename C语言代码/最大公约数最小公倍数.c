#include<stdio.h>
int maxyue(int a,int b)
{
    int c;
    while(b!=0)
    {
    c=a%b;
    a=b;
    b=c;
    }
    return a;
}
int maxbei(int a,int b)
{
    int s;
s=a/maxyue(a,b)*b;
return s;
}
int main()
{
    int a,b,s,n;
    scanf("%d %d",&a,&b);
    s=maxyue(a,b);
    n=maxbei(a,b);
    printf("%d ",s);
    printf("%d",n);
    return 0;}

