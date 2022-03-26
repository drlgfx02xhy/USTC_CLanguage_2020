#include<stdio.h>
int main()
{
	int a,b,m,n,r,temp,aa,bb;//ATTENTION:aa and bb are useful later
	printf("Please input two numbers:");
	scanf("%d%d",&a,&b);
	aa=a;bb=b;
	if(a<b)
	{
	    temp=b;
	    b=a;
	    a=temp;
	}
	if(a==b)
	    m=a;
	else
	{
	    do{
		    r=a%b;
		    a=b;
		    b=r;
	    }while(r);
	    m=a;//clear the mind.'m' should be given as 'a' rather than 'b'
	}
	n=aa*bb/m;//ATTENTION here!a,b have been altered,so we need to use aa and bb.
	printf("The greatest common divisor of a and b is%d,the least common mutiple is%d",m,n);
}

