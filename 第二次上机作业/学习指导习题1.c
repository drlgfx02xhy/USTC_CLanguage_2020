#include<stdio.h>
main()
{
	int a,b;
	char c1,c2;
	float d,e;
	double f,g;
	long m,n;
	unsigned int p,q;
	scanf("%d%d%c%c%f%f",&a,&b,&c1,&c2,&d,&e);
	scanf("%f,%f,%d,%d,%u,%u",&f,&g,&m,&n,&p,&q);
	printf("sizeof:%d,a=%d,b=%d\n",sizeof(int),a,b);
	printf("sizeof:%d,c1=%c,c2=%c\n",sizeof(char),c1,c2);
	printf("sizeof:%d,d=%-6.2f,e=%-6.2f\n",sizeof(float),d,e);
	printf("sizeof:%d,f=%-15.6f,g=%-15.12f\n",sizeof(double),f,g);
	printf("sizeof:%d,m=%ld,n=%ld\n",sizeof(long),m,n);
	printf("sizeof:%d,p=%u,q=%u\n",sizeof(unsigned),p,q);
}
/*���н��������printf�Ľ���� 
��һ�У�int4�ֽڣ�a��b��ֵΪ61��62
�ڶ��У�char1�ֽڣ�c1��c2��ֵΪ�ַ�a��b
�����У�float4�ֽ� ��d��e��ֵΪ3.56��-6.78
�����У�double8�ֽڣ�����������Ҵ��ڿո�λ
�����У�long4�ֽڣ�m,n��ֵΪ50000��-60000
�����У�unsigned int4�ֽڣ�p,q��ֵΪ32768,4000 */ 
/*�޸ĺ����������£� 
sizeof:4,a=61,b=62
sizeof:1,c1=a,c2=b
sizeof:4,d=3.56  ,e=-6.78
sizeof:8,f=0.000000       ,g=0.000000000000
sizeof:4,m=50000,n=-60000
sizeof:4,p=32768,q=4000
�����������г����쳣
ԭ������ĸ�ʽ��������ĳ��Ȳ����� ������������ݴ洢����*/ 
