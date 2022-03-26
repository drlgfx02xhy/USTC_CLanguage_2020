#include<stdio.h>
#define N 2
struct Student {
	int sex;
	char name[16];
	int birthyear;
}; 

void input(struct Student *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d:Name,SEX[m/f],BIRTHYEAR\n",i+1);
		scanf("%s%d%d",p[i].name,&p[i].sex,&p[i].birthyear);
	}
}
 
void count(struct Student *p,int n,int *c1994,int *cm,int *cf)
{
	int i;
	for(i=0;i<n;i++)
	{
		while(p[i].birthyear==1994)
			++*c1994;
		if(p[i].sex==1)
			++*cm;
		else 
			++*cf;
	}
}

int main()
{
 	struct Student classs[N];
	int c1994=0,cm=0,cf=0;
	input(classs,N);
	count(classs,N,&c1994,&cm,&cf);
	printf("male:%d\n",cm); 
	printf("female:%d\n",cf);
	printf("birthyear=1994:%d\n",c1994);
	return 0;
}
