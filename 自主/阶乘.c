#include<stdio.h> 
long jiecheng(int n)
{
	int i;
	int long fact=1;
	for(i=1;i<=n;i++)
		fact*=i;
	return fact;	
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d!=%ld",n,jiecheng(n));
}
