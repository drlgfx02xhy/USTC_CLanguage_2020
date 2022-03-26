#include<stdio.h>
int main()
{
	int i,j,k;
	long int number;
	for(i=10;i<=31;i++)
	    for(j=0;j<=31;j++)
	    {
	    	number=1000*i*i+j*j;
	        for(k=317;k<1000;k++)
	            if(k*k==number)
	            {
	    	        printf("%8ld",number);
	    	        break;
		        }
		}          
}
