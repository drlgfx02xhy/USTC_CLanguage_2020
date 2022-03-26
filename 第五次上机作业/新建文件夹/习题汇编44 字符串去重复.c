#include<stdio.h>
#define N 100
int main ()
{
	char name[N];
	int i,j;
	printf("Input some chars:\n");
	scanf("%s",name);
	for(i=0;name[i]!='\0';i++)
	{
		if(name[i]==name[i+1])
		{
		    for(j=i;name[j]!='\0';j++)
		        name[j]=name[j+1];
		    i--;
		}
	}
	puts(name);
	return 0;
}
