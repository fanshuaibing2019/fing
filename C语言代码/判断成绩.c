#include<stdio.h>
int main()
{const int pass=60;
int score;
while(score<101){

printf("请输入你的期末成绩："); 
scanf("%d",&score);
if(score>=pass){printf("恭喜你及格了,你可真是个天才少女小机灵鬼呢~\n");
}else
{printf("呐呐呐，不及格，恭喜你这半年学又白上了，回家吧，学校不适合你\n"); 

}
} return 0;
 
}
