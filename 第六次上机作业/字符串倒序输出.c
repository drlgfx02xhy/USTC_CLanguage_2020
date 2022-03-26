#include<stdio.h>
char reverse(char x[],int no)
{
	int i,j;
	char y[100];
	for(i=no-1,j=0;i>=0;i--,j++)
		y[j]=x[i];
	y[j]='\0';
	puts(y);
}
int main()
{
	int i,total=0;
	char x[100],y[100];
	char ch;
	printf("Please input some chars:\n");
	for(i=0;(ch=getchar())!=EOF;i++)
	{
		x[i]=ch;
		total++;
	}
	reverse(x,total);
}
