#include<stdio.h> 
#define PI 3.1415926
int main()
{
	double R,V;
	printf("��������İ뾶R:");
	scanf("%lf",&R);
	if(R<0){
	printf("R����Ϊ����");
	return 0;}
	else
	V=4.0/3*PI*R*R*R;
	printf("������Ϊ%f",V);
	return 0;
}
/*�����������ޱ���
Data test
Input:-1
Expected output: R����Ϊ����  Actual output:R����Ϊ����
Input 1 
Expected output: V=4.188790 Actual output:V=4.188790*/
