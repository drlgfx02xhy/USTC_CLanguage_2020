#include<stdio.h> 
#include<math.h>
int main()
{
	float a,b,c,q,term1,term2,realbig,realsmall;
	printf("请输入一元二次方程ax^2+bx+c=0的系数a,b,c:\n");
	scanf("%f%f%f",&a,&b,&c);
	q=b*b-4*a*c;
	if (a==0)
	{
	    if (b!=0)
	        printf("该方程有一个根，为：%f\n",-c/b);
	    else
	        printf("该方程无解\n");
    }
	else
	{
	    term1=b/(-2*a);
	    term2=sqrt(abs(q))/(2*a);
	    if(q==0)
	        printf("该方程有两个相同根，为%f",term1);
	        else if(q<0)
	                printf("该方程有两个复数根，为%f+%fi和%f-%fi\n",term1,term2,term1,term2);
	            else
	            {
	            	if(term1>=0)
	            	{
	            	    realbig=term1+abs(term2);
	            	    realsmall=c/(a*realbig);
	            	    printf("该方程有两个实数根，为%f和%f\n",realbig,realsmall);
	                } 
	            	else
	            	{
	            	    realbig=term1-abs(term2);
	            	    realsmall=c/(a*realbig);
	            	     printf("该方程有两个实数根，为%f和%f\n",realbig,realsmall);
	            	}
	                
	             
                }
    }
}
