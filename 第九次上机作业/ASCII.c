#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	FILE *fp;
	char x;
	if((fp=fopen("ASCIItest","r"))==NULL)
	{
		printf("Can't open this file!\n");
		exit(0);
	}
	int count[26]={0};
	while(!feof(fp))
	{
		x=fgetc(fp);
		count[x-'a']++;    
	}
	for(i=0;i<=25;i++)
		printf("%c:%d\n",i+'a',count[i]);
	return 0;
}
