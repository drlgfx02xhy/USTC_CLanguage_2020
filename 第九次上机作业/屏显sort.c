#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5
void main()
{
	FILE *fp;
	char c[2]; 
	if((fp=fopen("stu_sort1","rb"))==NULL)
	{
		printf("Can't open this file!");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(c,1,1,fp);
		printf("%s",c);
	}
	fclose(fp);
}

