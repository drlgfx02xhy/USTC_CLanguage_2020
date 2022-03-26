#include<stdio.h>
#define N 6
void xuanze(int a[])
{
	int i,j,k,temp;
	for(i=0;i<=N-2;i++)
	{
		k=i;
		for(j=i+1;j<=N-1;j++)
			if(a[j]>a[k])
				k=j;
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
}

void maopao(int a[])
{
	int i,j,temp;
	for(i=0;i<=N-2;i++)
	{
		for(j=i;j<=N-2-i;j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	}
}

void jiaohuan(int a[])
{
	int i,j,temp;
	for(i=0;i<=N-2;i++)
	{
		for(j=i+1;j<=N-1;j++)
		if(a[j]>a[i])
		{
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
}

int  main()
{
	int a[N]={1,2,3,4,5,6};
	int small=0,mid,big=N-1;
	int n;
	scanf("%d",&n);
	while(small<=big)
	{
		mid=(small+big)/2;
		if(n>a[mid])
			small=mid+1;
		if(n<a[mid])
			big=mid-1;
		if(n==a[mid])
		{
			printf("%d",mid);
			return 0;
		}
	}
	printf("Not found!");
	return -1;	
}
