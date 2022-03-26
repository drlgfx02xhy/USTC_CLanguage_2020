#include<stdio.h>
int N;
void alter(int (*x)[N],int n)
{
	int i,j,temp;
	for(i=0;i<=n-1;i++)
		for(j=i;j<=n-1;j++)
		{
			temp=*(*(x+i)+j);
			*(*(x+i)+j)=*(*(x+j)+i);
			*(*(x+j)+i)=temp;
		}
}
void main()
{
	int i,j;
	printf("Please input N*N matrix\nN=");
	scanf("%d",&N);
	int matrix[N][N];
	int (*p)[N]=matrix;
	for(i=0;i<=N-1;i++)
	{
		printf("请输入第%d行数字\n",i+1);
		for(j=0;j<=N-1;j++)
		{
			scanf("%d",*(p+i)+j);
		}
	}
	alter(matrix,N);
	printf("The new matrix is \n");
	for(i=0;i<=N-1;i++)
	{
		for(j=0;j<=N-1;j++)
			printf("%-3d",*(*(p+i)+j));
		printf("\n");
	}
}
