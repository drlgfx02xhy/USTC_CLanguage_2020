#include<stdio.h> 
#include<math.h>
#define PI 3.1415926
int main() 
{
	double r,h,C,Sdi,Sce,V;
	printf("������Բ׶���r��h��");
	scanf("%lf%lf",&r,&h);
	C= 2*PI*r;
	Sdi=PI*r*r;
	Sce=PI*r*sqrt(r*r+h*h);
	V=1.0/3*Sdi*h;
	printf("�����ܳ�Ϊ%f\n�����Ϊ%f\n�����Ϊ%f\n���Ϊ%f\n",C,Sdi,Sce,V);
	return 0;
}
/*�����������ޱ���
Data test
Input:1 1
Expected output:�����ܳ�Ϊ6.283185
�����Ϊ3.141593
�����Ϊ4.442883
���Ϊ1.047198
Actual output:�����ܳ�Ϊ6.283185
�����Ϊ3.141593
�����Ϊ4.442883
���Ϊ1.047198
Input: 2 2
Expected output: �����ܳ�Ϊ12.566370
�����Ϊ12.566370
�����Ϊ17.771531
���Ϊ8.377580
Actual output:�����ܳ�Ϊ12.566370
�����Ϊ12.566370
�����Ϊ17.771531
���Ϊ8.377580*/
