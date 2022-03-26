#include<stdio.h> 
int maxdiv(int x,int y)
{
	int i,max=1;
	for(i=1;i<=x&&i<=y;i++)
		if((x%i==0)&&(y%i==0))
			max=i;
	return max;
}
int minmul(int x,int y,int z)
{
	int maxdiv(int x,int y);
	int min; 
	z=maxdiv(x,y);
	min=x*y/z;
	return min;
}
int main()
{
	int a,b,c;
	printf("Please input two numbers:\n");
	scanf("%d%d",&a,&b);
	printf("maxdiv is %d\n",maxdiv(a,b));
	printf("minmul is %d\n",minmul(a,b,c));
}
