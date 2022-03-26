#include<stdio.h> 
int main()
{
	int i,j,N,t;
	int i_num[100];
	printf("请选择输入的数字个数：\n");
	scanf("%d",&N);
	printf("请输入这些数字：\n");
	for (i=0;i<N;i++)
	    scanf("%d",&i_num[i]);
	for (i=0;i<N;i++)
	{
	    for (j=0;j<N-i;j++)
	    {
	        if(i_num[j]>=i_num[j+1])
	        {
	            t=i_num[j];
	            i_num[j]=i_num[j+1];
	            i_num[j+1]=t;
	        }
	    }
	        
	}
	for (i=0;i<10;i++) 
	    printf("%4d",i_num[i]);  
	return 0;
}
