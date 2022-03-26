#include<stdio.h>
#define PRODUCT(a,b) a*b
void fun(int i)
{
	static int x=1;
	x+=PRODUCT(x+i,x-i);
	printf("x=%d\n",x);
}
int main()
{
	int i,x=1;
	for(i=1;i<=3;i++,x++)
		fun(x+i);
}
