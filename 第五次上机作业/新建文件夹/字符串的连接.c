#include<stdio.h>
void udf_strcat(char s[100],char t[100])
{
	int i,j;
	for (i=0;s[i];i++);
    for (j=0;s[i]=t[j];i++,j++);
    printf("%s",s);
}

int main ()
{
	int i=0;
	char c,d;
	char s[100] = "";
	char t[100] = "";
	printf("input s[]:\n");
	for(i=0;(c=getchar())!='\n';i++)
		s[i]=c;
	printf("input t[]:\n");
	scanf("%c",&d);
	for(i=0;d!='\n';i++)
	{
		t[i]=d;
		scanf("%c",&d);
	}
	udf_strcat(s,t);
	return 0;
}
