#include<stdio.h>
int main()
{
	char x;
	printf("������һ��Сд��ĸ��");
	scanf("%c",&x);
	x-=32;
	printf("%c",x);
	return 0;
}
/*�����������ޱ���
����һ����������a���в��������
������+�ĳ�-������������
����ԭ��û�и������ԭ��ASCII�����ŵĴ�д��ĸ���ŵ�Сд��ĸ�� 
Data test
Input a 
Expected output:a
Actual output:A */ 
