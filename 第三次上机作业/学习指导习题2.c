#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,p,S;
	printf("请输入三角形三条边的数值：");
	scanf("%f%f%f",&a,&b,&c);
	if(a+b>c&&a+c>b&&b+c>a)
	{
		if(a==b||b==c||c==a)
		{
			if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
			printf("该三角形为等腰直角三角形\n");
		    else if(a==b&&b==c)
		            printf("该三角形为等边三角形\n");
		        else  
		            printf("该三角形为等腰三角形\n");
		}
		else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
		         printf("该三角形为直角三角形\n");
	        else 
			     printf("该三角形为一般三角形\n");
	    p=(a+b+c)/2;
	    S=sqrt(p*(p-a)*(p-b)*(p-c));
	    printf("该三角形面积为%f\n",S);
	}
    else 
	    printf("DATA ERROR!");
}

