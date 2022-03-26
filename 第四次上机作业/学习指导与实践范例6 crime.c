#include<stdio.h>
/*1:interpret each clue(false0 or treu1)
2:run a circle and judge clues
3:output criminal(s)*/
int judge(int x)
{
	if(x==0)
	    printf("²»ÊÇ×ï·¸\n");
	if(x==1)
	    printf("ÊÇ×ï·¸\n");
}
int main()
{
	int c1,c2,c3,c4,c5,c6;
	int a,b,c,d,e,f;
	for(a=0;a<=1;a++)
	    for(b=0;b<=1;b++)
	        for(c=0;c<=1;c++)
	            for(d=0;d<=1;d++)
	                for(e=0;e<=1;e++)
	                    for(f=0;f<=1;f++)
	                    {
	                        c1=a||b;
	                        c2=((a&&e)||(e&&f)||(f&&a));//attention.(a&&e&&f)is included. 
	                        c3=!(a&&d);
	                        c4=(b&&c)||(!b&&!c);
	                        c5=((c&&!d)||(!c&&d));
	                        c6=!(!d&&e);
	                        if(c1&&c2&&c3&&c4&&c5&&c6)
	                        {
	                        	printf("A:");judge(a);
	                        	printf("B:");judge(b);
	                        	printf("C:");judge(c);
	                        	printf("D:");judge(d);
	                        	printf("E:");judge(e);
	                        	printf("F:");judge(f);
							}
						}
}
