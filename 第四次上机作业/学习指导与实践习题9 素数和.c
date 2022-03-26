#include<stdio.h>
#define MAXLEN 500
//掌握筛法求素数方法 
int main()
{
	int index[MAXLEN],i,j;
	int bingo[MAXLEN],next=0,sum=0;
	for(i>=0;i<=MAXLEN;i++)
	    index[i]=1;
	for(i=2;i<=MAXLEN;i++)
	{
		if(index[i])
		{
		    bingo[next++]=i;
		    for(j=2*i;j<=MAXLEN;j+=i)
		        index[j]=0;
	    }
	}
    {
    	for(i=next-1;i>=0;i--)
    	sum+=bingo[i];
	}
	printf("Sum=%d",sum);
}
