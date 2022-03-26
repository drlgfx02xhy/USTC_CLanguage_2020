#include<stdio.h>
int main()
{
	char x;
	printf("请输入一个小写字母：");
	scanf("%c",&x);
	x-=32;
	printf("%c",x);
	return 0;
}
/*编译正常，无报错。
但第一次运行输入a运行不出结果。
第七行+改成-后运行正常。
错误原因：没有搞清楚，原来ASCII码先排的大写字母再排的小写字母。 
Data test
Input a 
Expected output:a
Actual output:A */ 
