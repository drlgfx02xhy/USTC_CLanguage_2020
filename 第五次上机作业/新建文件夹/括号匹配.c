#include<stdio.h>
#define N 100
int main()
{
	int i,sum=0,x=0,y=0;
	char ch;
	char exp[N];
	scanf("%s",exp);
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
			x++;
		if(exp[i]==')')
			x--;
		if(x<0)
		{
			printf("��ƥ�䣡");
			return 0;
		}
	}
	if(x!=0)
		printf("��ƥ�䣡");
	else
		printf("ƥ�䣡"); 
}
