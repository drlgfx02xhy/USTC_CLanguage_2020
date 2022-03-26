#include<stdio.h> 
int sum7(int x,int y)
{
	int i,sum=0;
	for(i=x;i<=y;i++)
		if(i%7==0)
			sum+=i;
	return sum;
}
int main()
{
	int m,n;
	do{
		printf("Please input m&n(m<n):\n"); 
		scanf("%d%d",&m,&n);
	}while(m>=n);
	printf("The sum is %d",sum7(m,n));
	return 0;
}
