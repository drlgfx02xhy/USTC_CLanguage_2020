#include<stdio.h> 
#define PI 3.141592
int main()
{double R,H,V;
printf("请输入圆柱体的底面半径R和高度H\n");
scanf("%lf%lf",&R,&H);
V=PI*R*R*H;
printf("圆柱体体积为%lf",V);
return 0;
}

