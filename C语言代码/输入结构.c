/*#include<stdio.h>
struct point{
	int x;
	int y;
}; 
void getstruct(struct point p);
void output(struct point p);
void main()
{
	struct point y={0,0};
	getstruct(y);
	output(y);
}
void getstruct(struct point p)
{
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	printf("%d,%d\n",p.x,p.y);
}
void output(struct point p)
{
	printf("%d,%d\n",p.x,p.y);
}
*/   //´íÎóÊ¾·¶;
#include<stdio.h>
struct point{
	int x;
	int y;
}; 
struct point getstruct();
void output(struct point p);
void main()
{
	struct point y={0,0};
	y=getstruct();
	output(y);
}
struct point getstruct()
{
	struct point p;
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	printf("%d,%d\n",p.x,p.y);
	return p;
}
void output(struct point p)
{
	printf("%d,%d\n",p.x,p.y);
} 
