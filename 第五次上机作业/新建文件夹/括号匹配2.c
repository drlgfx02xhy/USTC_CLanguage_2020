#include<stdio.h>
#define N 100
int main()
{
	int i,sum=0,x=0;
	char ch;
	char exp[N];
	for(i=0;(exp[i]=getchar()!='\n');i++);
	for(i=0;i<100;i++)
	{
		if(exp[i]=='(')
			x++;
		if(exp[i]==')')
			x--;
		if(x!=y)
		{
			printf("²»Æ¥Åä£¡");
			return 0;
		}
	}
	printf("Æ¥Åä£¡");
}
