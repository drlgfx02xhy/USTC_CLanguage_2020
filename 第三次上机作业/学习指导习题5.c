#include<stdio.h>
int main()
{
	int score;
	printf("请输入您的百分制成绩：\n"); 
	scanf("%d",&score);
	if(score<=100&&score>=0)
    {   
        switch (score/10)
        {   
            case 10:
	        case 9:printf("%d A",score);break;
	        case 8:printf("%d B",score);break;
	        case 7:printf("%d C",score);break;
	        case 6:printf("%d D",score);break;
	        default:printf("%d E",score);break;
        }
    }
    else
        printf("非法输入！"); 
}
	

