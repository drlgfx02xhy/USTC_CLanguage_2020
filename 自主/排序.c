#include<stdio.h> 
int main()
{
	int i,j,N,r,t;
	int i_num[100];
	printf("请选择输入的数字个数：\n");
	scanf("%d",&N);
	printf("请输入这些数字：\n");
	for (i=0;i<N;i++)
	    scanf("%d",&i_num[i]);
	printf("请选择排列方式：1-正序（从小到大），2-倒序（从大到小）\n");
	scanf("%d",&r);
	for (i=0;i<N;i++)
	{
	    for (j=0;j<N-i-1;j++)
	    {
	        if (r==1)
	        {
	            if(i_num[j]>=i_num[j+1])
	            {
	                t=i_num[j];
	                i_num[j]=i_num[j+1];
	                i_num[j+1]=t;
	            }
	        }
	        if (r==2) 
	        {
			    if(i_num[j]<i_num[j+1])
	            { 
				    t=i_num[j];
	                i_num[j]=i_num[j+1];
	                i_num[j+1]=t;
				}
	        }
	    }
	}
	for (i=0;i<N;i++) 
	    printf("%4d",i_num[i]);  
	return 0;
}
