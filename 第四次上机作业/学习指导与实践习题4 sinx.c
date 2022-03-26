#include<stdio.h> 
#include<math.h>
#define PI 3.1415926
double fact(int n)
{
	if(n==0)
	return 1;
	return fact(n-1)*n;
}
int main()
{
	double x,sum=0,term=1;
	int k,n=1,t=1;
	printf("ÇëÊäÈëxµÄÖµ£º\n");
	scanf("%lf",&x);
	for(k=0;k<=(int)x;k++)
	{
		if(0<=x+2*k*PI&&x+2*k*PI<=2*PI)
			x=x+2*k*PI;
		if(0<=x-2*k*PI&&x-2*k*PI<=2*PI)
			x=x-2*k*PI;
	}
	while(term>=1e-5)
	{
		term=pow(x,2*n-1)/fact(2*n-1);
		sum+=t*term;
		t=-t;
		n++;
	}
	printf("sinx=%f",sum);
	return 0;
}
