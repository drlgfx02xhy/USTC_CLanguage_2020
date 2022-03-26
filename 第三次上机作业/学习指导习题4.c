#include<stdio.h>
int main()
{
	double x,y;
	printf("请输入自变量x的值为："); 
	scanf("%lf",&x);
	if(x<-3||-3<x&&x<0)
	    y=(x+3)*(x-2);
	else if(0<=x&&x<2||2<x&&x<3||3<x)
	        y=(x-2)*(x-3);
	    else
		    y=x*x-x-1;
    printf("x=%f,f(x)=%f",x,y);		 
}
/*x=-5.0 y=14.000000;
  x=-3.0 y=11.000000;
  x=1.0 y=2.000000;
  x=2.0 y=1.000000;
  x=2.5 y=-0.250000;
  x=3.0 y=5.000000;
  x=5.0 y=6.000000*/
