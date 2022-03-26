#include<stdio.h> 
#include<math.h>
#define PI 3.1415926
int main() 
{
	double r,h,C,Sdi,Sce,V;
	printf("请输入圆锥体的r和h：");
	scanf("%lf%lf",&r,&h);
	C= 2*PI*r;
	Sdi=PI*r*r;
	Sce=PI*r*sqrt(r*r+h*h);
	V=1.0/3*Sdi*h;
	printf("底面周长为%f\n底面积为%f\n侧面积为%f\n体积为%f\n",C,Sdi,Sce,V);
	return 0;
}
/*编译正常，无报错。
Data test
Input:1 1
Expected output:底面周长为6.283185
底面积为3.141593
侧面积为4.442883
体积为1.047198
Actual output:底面周长为6.283185
底面积为3.141593
侧面积为4.442883
体积为1.047198
Input: 2 2
Expected output: 底面周长为12.566370
底面积为12.566370
侧面积为17.771531
体积为8.377580
Actual output:底面周长为12.566370
底面积为12.566370
侧面积为17.771531
体积为8.377580*/
