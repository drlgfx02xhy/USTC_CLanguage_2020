#include<stdio.h> 
#include<math.h>
int main()
{ 
	int m,n,i,k;
	for (n=3;n<=10000;n=n+2){
	    k=sqrt(n);
	    for (i=2;i<=k;i++)
	        if (n%i==0)break;
	    if(i==1+k){
	        	m++;
	        	printf("%10d",n);
	        	if(m%8==0)
	        	    printf("\n");
			}
	}
	getchar();
}
