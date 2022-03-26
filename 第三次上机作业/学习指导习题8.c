#include<stdio.h>
int main()
{   
    char x;
	printf("请输入一个字母：");
	x=getchar();
	switch(x)
	{
	    case 'a':
	    case 'e':
	    case 'i':
	    case 'o':
	    case 'u':
	    case 'A':
	    case 'E':
	    case 'I':
	    case 'O':
	    case 'U':printf("YES\n");
		         break;
	    default:printf("NO\n");
	}
	if(x>='a'&&x<='z')
	{
	    printf("%c的小写ASCII码为%d\n",x,x);
	    x+='A'-'a';
	    printf("%c的大写ASCII码为%d\n",x,x);
	} 
	else if(x>='A'&&x<='Z')
	    {
	        printf("%c的大写ASCII码为%d\n",x,x);
	        x-='A'-'a';
	        printf("%c的小写ASCII码为%d\n",x,x);
		}
	    else 
		    printf("非法输入！");
} 
