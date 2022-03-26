#include<stdio.h>
int SWAP(double x)
{
	unsigned char *p;
	p=(unsigned char*)&x;
	int i;
	for(i=7;i>=0;i--)
	    printf("%02x ",*(p+i));
	return 1;
}

int main()
{
	double x;
	printf("Now please input the number:\n");
	scanf("%lf",&x);
	SWAP(x);
	return 0;
}
