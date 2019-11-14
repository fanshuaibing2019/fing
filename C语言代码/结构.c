/*#include<stdio.h>
struct date{
	int month;
	int day;
	int year;
};
int main()
{
	struct date today;
	today.month=4;
	today.day=9;
	today.year=2019;
	printf("Today's date is %i-%i-%i.\n",
			today.year,today.month,today.day);
	return 0;
}
*/
#include<stdio.h>
struct date{
	int month;
	int day;
	int year;
};
int main(int argc,char const*argv[])
{
	struct date today={04,9,2019};//today=(struct date){04,9,2019};
	struct date thismonth={.month=7,.year=2014};
	struct date day;
	day=today;
	day.year=2015;
	struct date *p=&today;
	printf("Today's month is %i-%i-%i.\n",
			today.year,today.month,today.day);
	printf("This month is %i-%i-%i.\n",
			thismonth.year,thismonth.month,thismonth.day);
	printf("The day's date is %i-%i-%i.\n",
			day.year,day.month,day.day);
	printf("address(µÿ÷∑) of today is %p\n",p);
	return 0;
}
