#include<stdio.h>
#include<stdlib.h>
void cal(int *p1,int *p2,int *p,int n)
{
	int i;
	for(i=0;i<=n-1;i++)
		*(p+i)=(*(p1+i))*(*(p2+i));
}
void main()
{
	int *s1,*s2,*s;
	int N,i;
	printf("Please input N:\n");
	scanf("%d",&N);
	printf("Now input the first line:\n");
	s1=(int *)malloc(N*sizeof(int));//动态分配空间 
	for(i=0;i<=N-1;i++)
		scanf("%d",s1+i);
	printf("Now input the second line:\n");
	s2=(int *)malloc(N*sizeof(int));
	for(i=0;i<=N-1;i++)
		scanf("%d",s2+i);
	s=(int *)malloc(N*sizeof(int));
	cal(s1,s2,s,N);
	printf("(");
	for(i=0;i<=N-1;i++)
		printf("%-3d",*(s1+i));
	printf(")*(点乘)(");
	for(i=0;i<=N-1;i++)
		printf("%-3d",*(s2+i));
	printf(")=(");
	for(i=0;i<=N-1;i++)
		printf("%-3d",*(s+i));
	printf(")");
}
