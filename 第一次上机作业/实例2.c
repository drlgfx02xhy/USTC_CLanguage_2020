#include<stdio.h> 
#include<math.h>
int main()
{double a,b,c,d,delta,root1,root2;
printf("请依次输入二次项系数、一次项系数、常数项：\n");
scanf("%lf%lf%lf",&a,&b,&c);
d=-b/(2*a);delta=pow(b,2)-4*a*c;
if(a==0)
{
printf("二次项系数不能为0!");
return 0; 
}
if(delta==0)        
    {
	printf("该方程有两个相同的根%lf",d);
	}
	else if(delta>0)
	    {
	    root1=d+sqrt(delta)/(2*a);root2=d-sqrt(delta)/(2*a);
	    printf("该方程有两个不同根，分别为%lf和%lf",root1,root2);
	    return 0;
		}
		else
		{
		root1=sqrt(abs(delta))/(2*a);
		root2=sqrt(abs(delta))/(2*a);
		printf("该方程有两个共轭复数根，分别为%lf+i%lf和%lf-i%lf",d,root1,d,root2);
		}                                                     
return 0;
}
