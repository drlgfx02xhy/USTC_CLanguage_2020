#include<stdio.h>
int main()
{
	int yy,mm,dd;
	printf("Please input Year and Month");
	scanf("%d%d",&yy,&mm);
	switch(mm)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:dd=31;break;
		case 4:
		case 6:
		case 9:
		case 11:dd=30;break;
		case 2:if(yy%4==0&&yy%100!=0||yy%400==0)
		           dd=29;
		       else
			       dd=28;
		       break;
	    default:printf("input error");
	            break;
	}
	printf("The length of %d is %d",mm,dd);
}
