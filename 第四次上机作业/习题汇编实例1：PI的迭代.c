#include<stdio.h> 
int main()
{
	long i,n;
	double pi,di;
	printf("���������������\n");
	scanf("%ld",&n);
	pi=2.0;
	di=1.0;
	for (i=1;i<=n;i++) 
	{ 
		pi*=4*di*di/(2*di-1)/(2*di+1);
		di+=1;
	} 
	printf("����%ld�ε���,PI��ֵΪ%.15f",n,pi);
}
