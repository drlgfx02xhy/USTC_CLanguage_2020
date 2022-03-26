#include<stdio.h>
int judge(int n)
{
	int i,sushu=1;
	for(i=2;i<n;i++)
		if(n%i==0)
			sushu=0;
	return sushu;
}
int reverse(int n)
{
	int temp=0;
	while(n!=0)
	{
		temp=(temp*10+n%10);
		n/=10;
	}
	return temp;
}
int main()
{
	int i,m,n,k=0;
	do{
		printf("Please input m&n(m<n):\n"); 
		scanf("%d%d",&m,&n);
	}while(m>=n);
	for(i=m;i<=n;i++)
	{
		if(judge(i)&&judge(reverse(i)))
		{
			printf("%d\n",i);
			k=1;
		}
	}
	if(!k)	
		printf("0");
	return 0;
}
