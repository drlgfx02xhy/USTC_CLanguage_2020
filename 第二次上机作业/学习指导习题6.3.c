#include<stdio.h>
int main()
{
	double x;
	x=(3.31E18+2.10E-7)/(7.16E5+2.01E3);
	printf("x=%f",x);
	return 0;
}
/*
编译正常，无报错。
Data test
Expected output:x=4609963649531.343700
Actual output:x=4609963649531.343700*/
