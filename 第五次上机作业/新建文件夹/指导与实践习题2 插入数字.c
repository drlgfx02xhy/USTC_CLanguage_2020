#include<stdio.h> 
int main()
{
	int x[21];
	int m,n,i,k;
	printf("Please input n(n<=20):\n");
	scanf("%d",&n);
	printf("Please input n numbers:\n");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	printf("Please determine m:\n"); 
	scanf("%d",&m);
	printf("Insert number:\n");
	scanf("%d",&k);
	for(i=n-1;i>=m;i--)
		x[i+1]=x[i];
	x[m]=k;
	for(i=0;i<n+1;i++)
		printf("%4d",x[i]);
	return 0;
}
