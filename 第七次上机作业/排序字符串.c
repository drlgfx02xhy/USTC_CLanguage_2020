#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main ()
{
	void sort(char *s[],int n);
	int i,N;
	printf("How many lines do you want to input?\n");
	scanf("%d",&N);
	char *str[N];
	for(i=0;i<N;i++)
	{
		str[i]=(char *)malloc(4);
	}
	void input(char *input[],int n);
	input(str,N);
	sort(str,N);
	printf("new of string is:\n");
	for(i=0;i<N;i++)
	    printf("%s\n",str[i]);
}

void input(char *input[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Please input the %d line:\n",i+1);
		scanf("%s",input[i]);
	}
}

void sort(char *s[],int n)
{
	char *temp;
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		    if(strcmp(s[k],s[j])>0)
		        k=j;
		if(k!=i)
		{
			temp=s[i];
			s[i]=s[k];
			s[k]=temp;
		}
	}
}
