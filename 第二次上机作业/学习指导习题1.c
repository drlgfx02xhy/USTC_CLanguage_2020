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
/*运行结果分析：printf的结果中 
第一行：int4字节，a、b赋值为61、62
第二行：char1字节，c1、c2赋值为字符a、b
第三行：float4字节 ，d，e赋值为3.56，-6.78
第四行：double8字节，左对齐输入且存在空格补位
第五行：long4字节，m,n赋值为50000，-60000
第六行：unsigned int4字节，p,q赋值为32768,4000 */ 
/*修改后，输出结果如下： 
sizeof:4,a=61,b=62
sizeof:1,c1=a,c2=b
sizeof:4,d=3.56  ,e=-6.78
sizeof:8,f=0.000000       ,g=0.000000000000
sizeof:4,m=50000,n=-60000
sizeof:4,p=32768,q=4000
分析：第四行出现异常
原因：输入的格式符允许储存的长度不够， 导致输入的数据存储错误。*/ 
