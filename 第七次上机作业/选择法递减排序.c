#include<stdio.h>
void sort(int *x,int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(*(x+j)>*(x+i))
				k=j;
		temp=*(x+k);
		*(x+k)=*(x+i);
		*(x+i)=temp;
	}
}
void main()
{
	int N,i;
	printf("how many numbers do you want to input\n");
	scanf("%d",&N);
	int a[N];
	printf("Please input these numbers:\n");
	for(i=0;i<=N-1;i++)
		scanf("%d",&a[i]);
	sort(a,N);
	for(i=0;i<=N-1;i++)
		printf("%6d",a[i]);
}
