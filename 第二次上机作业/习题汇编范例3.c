#include<stdio.h> 
#include<stdlib.h>
int main()
{
	char c;
	while((c=getchar())!=EOF)/*在windows系统中EOF=Ctrl+z*/ 
	putchar(c);
	return 0;
}
/*编译正常，无报错。
Data test
Input: aaa
Expected output: aaa  Actual output:aaa
Input Crtl+z  
Expected output:return value 0   Actual output:return value 0 */
