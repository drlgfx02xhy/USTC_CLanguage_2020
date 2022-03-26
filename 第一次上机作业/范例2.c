#include <math.h>
#include <stdio.h>
main ()
{double a,b,c,p,d,x1,x2;
a=1,0;b=-(1.0e+12+1.0);c=1.0e+12;
p=sqrt(b*b-4*a*c);
d=2*a;
x1=(-b+p)/d;
x2=(-b-p)/d;
printf("x1=%e\n x2=%e\n",x1,x2);
return 0;
}
