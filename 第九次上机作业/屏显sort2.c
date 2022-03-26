#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int len; 
	FILE *fp; 
	if((fp=fopen("stu_sort1","rb"))==NULL)
	{
		printf("Can't open this file!");
		exit(0);
	}
	fseek(fp,0,2);
	len=ftell(fp);
	char c[len];
	rewind(fp);
	fread(c,len,1,fp);
	fclose(fp);
	puts(c);
}

