#include<stdio.h>
#define MAXLEN 16
int main()
{
	int inform,outform,c,i,next;
	char digits[MAXLEN],a,b,ch;
	next=0;
	while((ch=getchar())<='9'&&ch>='0')
	    digits[next++]=ch;//these 3 lines above: an efficient means of putting chars into digits
	a=getchar();
	if(a<='9'&&a>='2')
	    inform=a-'0';
	else 
	    inform=10;//from if to else:NOTE 1,equivalent to NOTE 2
	getchar();
	b=getchar();
	outform=(b<='9'&&b>='2'?(b-'0'):10);//this line:NOTE 2,equivalent to NOTE 1
	for(c=i=0;i<=next-2;i++)
	    c=(c+digits[i]-'0')*inform;
	c=c+digits[i]-'0';
	next=0;
	do 
	    digits[next++]=c%outform+'0';
	while((c/=outform)>0);
	for (i=next-1;i>=0;i--)
	    printf("%c",digits[i]);
}
