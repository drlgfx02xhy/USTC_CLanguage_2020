#include<stdio.h> 
#include<stdlib.h>
int main()
{
	char c;
	while((c=getchar())!=EOF)/*��windowsϵͳ��EOF=Ctrl+z*/ 
	putchar(c);
	return 0;
}
/*�����������ޱ���
Data test
Input: aaa
Expected output: aaa  Actual output:aaa
Input Crtl+z  
Expected output:return value 0   Actual output:return value 0 */
