#include<stdio.h> 
#include<math.h> 
int main()
{
	double x=1.5,y,fx;
	do{
		y=2*x*x*x-4*x*x+3*x-6;
		fx=6*x*x-8*x+3;
		x-=y/fx;
	}while(fabs(y)>=1e-6);//float:fabs;int:abs;attention 10^-6 ought to be 1e-6
	printf("x=%f",x);
}
