#include<stdio.h> 
int main()
{
	int a,b,c,max;
	printf("«Î ‰»Îa,b,c\n");
	scanf("%d%d%d",&a,&b,&c);
	max=a;
	if(max<b)
	max=b;
	if(max<c)
	max=c;
	printf("max=%d",max);
	return 0;
}
