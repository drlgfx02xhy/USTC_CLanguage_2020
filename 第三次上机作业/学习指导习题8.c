#include<stdio.h>
int main()
{   
    char x;
	printf("������һ����ĸ��");
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
	    printf("%c��СдASCII��Ϊ%d\n",x,x);
	    x+='A'-'a';
	    printf("%c�Ĵ�дASCII��Ϊ%d\n",x,x);
	} 
	else if(x>='A'&&x<='Z')
	    {
	        printf("%c�Ĵ�дASCII��Ϊ%d\n",x,x);
	        x-='A'-'a';
	        printf("%c��СдASCII��Ϊ%d\n",x,x);
		}
	    else 
		    printf("�Ƿ����룡");
} 
