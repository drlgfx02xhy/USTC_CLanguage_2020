#include<stdio.h> 
#include<math.h>
int main()
{
	float a,b,c,q,term1,term2,realbig,realsmall;
	printf("������һԪ���η���ax^2+bx+c=0��ϵ��a,b,c:\n");
	scanf("%f%f%f",&a,&b,&c);
	q=b*b-4*a*c;
	if (a==0)
	{
	    if (b!=0)
	        printf("�÷�����һ������Ϊ��%f\n",-c/b);
	    else
	        printf("�÷����޽�\n");
    }
	else
	{
	    term1=b/(-2*a);
	    term2=sqrt(abs(q))/(2*a);
	    if(q==0)
	        printf("�÷�����������ͬ����Ϊ%f",term1);
	        else if(q<0)
	                printf("�÷�����������������Ϊ%f+%fi��%f-%fi\n",term1,term2,term1,term2);
	            else
	            {
	            	if(term1>=0)
	            	{
	            	    realbig=term1+abs(term2);
	            	    realsmall=c/(a*realbig);
	            	    printf("�÷���������ʵ������Ϊ%f��%f\n",realbig,realsmall);
	                } 
	            	else
	            	{
	            	    realbig=term1-abs(term2);
	            	    realsmall=c/(a*realbig);
	            	     printf("�÷���������ʵ������Ϊ%f��%f\n",realbig,realsmall);
	            	}
	                
	             
                }
    }
}
