#include<stdio.h>
int adjust(char x)
{
	if(('x'>=48)&&('x'<=57))
		x=x+100;
	if(('x'>=97)&&('x'<=122))
		x=x-32;
	return x;	
}
int compare(char *s1,char *s2)
{
	int i;
	for(i=0;(s1[i]!=0)||(s2[i]!=0);i++)
	{
		if(adjust(*(s1+i))>adjust(*(s2+i)))
			return 1;
		if(adjust(*(s1+i))<adjust(*(s2+i)))
			return -1;
	}
	return 0;
}
void main()
{
	char a1[100],a2[100];
	int k;
	printf("Please input string1:\n");
	scanf("%s",a1);
	printf("Please input string2:\n");
	scanf("%s",a2);
	k=compare(a1,a2);
	if(k==0)
		printf("相等"); 
	if(k>0)
		printf("\n\n%s排在前面\n%s排在后面",a2,a1);
	if(k<0)
		printf("\n\n%s排在前面,\n%s排在后面",a1,a2);
}
