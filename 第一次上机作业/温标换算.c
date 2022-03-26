#include<stdio.h> 
int main()
{double f,c;
printf("请输入华氏温度：\n");
scanf("%lf",&f);
c=5.0/9.0*(f-32);
printf("摄氏温度为:%lf\n",c);
return 0;
}
