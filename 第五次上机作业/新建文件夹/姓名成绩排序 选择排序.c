#include<stdio.h>
#include<string.h>
#define N 3 
int main ()
{
	char name[N][20]={0};
	char p[20];
	int score[N];
	int i,j,k,temp;
	printf("Input the name first:\n");
	for(i=0;i<=N-1;i++)
	    for(j=0;(name[i][j]=getchar())!='\n';j++);
	printf("Then input the scores\n");
	for(i=0;i<=N-1;i++)
	    scanf("%d",&score[i]);
	for(i=0;i<N-1;i++)
	{
		k=i;
		for(j=i+1;j<N;j++)
		    {
		    	if(score[j]>score[k])
		    	    k=j;
			}
		if(k!=i)
		{
			temp=score[k];
			score[k]=score[i];
			score[i]=temp;
			strcpy(p,name[k]);
			strcpy(name[k],name[i]);
			strcpy(name[i],p);
		}
	}
	printf("The rank is:\n");
	for(i=0;i<N;i++)
	{   
	    printf("%d ",score[i]);
		for(j=0;name[i][j]!='\n';j++)
		    printf("%c",name[i][j]);
		printf("\n");
	}
	return 0;
}
