#include<stdio.h> 
int maxdiv,minmul;
void maxdivi(int x,int y)
{
	int i,max=1;
	for(i=1;i<=x&&i<=y;i++)
		if((x%i==0)&&(y%i==0))
			max=i;
	maxdiv=max;
}
void minmult(int x,int y)
{
	void maxdivi(int x,int y);
	minmul=x*y/maxdiv;
	
}
int main()
{
	int x,y;
	printf("Please input two numbers:\n");
	scanf("%d%d",&x,&y);
	maxdivi(x,y);
	minmult(x,y);
	printf("%d\n",maxdiv);
	printf("%d\n",minmul);
}
