#include<stdio.h> 
int totaldays;
int leap_year(int year)
{
	int i;
	if(year%4==0&&year%100!=0||year%400==0)
		i=1;
	else
		i=0;
	return i;
}
int len_month(int year,int month)
{
	int days;
	if(month==2) 
		if(leap_year)
			days=29;
		else 
			days=28;
	else if(month==4||month==6||month==9||month==11)
			days=30;
		else 
			days=31;
	return days;
}
void len_day(int year,int month,int date)
{
	int i;
	for(i=1,totaldays=0;i<month;i++)
		totaldays+=len_month(year,i);
	totaldays+=date;
}
int main()
{
	int year,month,date;
	printf("Please input year,month & date:\n");
	scanf("%d%d%d",&year,&month,&date);
	leap_year(year);
	len_month(year,month);
	len_day(year,month,date);
	printf("It's the %dst day of the year.\n",totaldays);
}
