#include<stdio.h>
int temp;
#define reverse(a,b) a=b-a,b=b-a,a=a+b; 
int main()
{
	float x,y;
	printf("Please input two numbers:\n");
	scanf("%f%f",&x,&y);
	reverse(x,y);
	printf("%f %f",x,y);
	return 0;
}
