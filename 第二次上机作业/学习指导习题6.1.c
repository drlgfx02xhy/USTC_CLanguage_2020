#include<stdio.h> 
#define PI 3.1415926
int main()
{
	double R,V;
	printf("请输入球的半径R:");
	scanf("%lf",&R);
	if(R<0){
	printf("R不能为负数");
	return 0;}
	else
	V=4.0/3*PI*R*R*R;
	printf("球的体积为%f",V);
	return 0;
}
/*编译正常，无报错。
Data test
Input:-1
Expected output: R不能为负数  Actual output:R不能为负数
Input 1 
Expected output: V=4.188790 Actual output:V=4.188790*/
