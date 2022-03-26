#include<stdio.h>
void search(float *x,int n,float *p,float *q)//p max,q min
{
	int i;
	for(i=1;i<=n-1;i++)
	{
		if(*(x+i)>*p)
			*p=*(x+i);
		if(*(x+i)<*q)
			*q=*(x+i);
	}
 } 
 int main()
 {
 	int i,N;
 	printf("How many numbers do you want to input:\n");
 	scanf("%d",&N);
 	float a[N];
 	printf("Now input these numbers:\n");
 	for(i=0;i<N;i++)
 		scanf("%f",a+i);
 	float max=a[0],min=a[0];
 	search(a,N,&max,&min);
 	printf("Max is%f\nMin is%f\n",max,min);
 }
