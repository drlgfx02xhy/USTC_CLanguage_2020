#include<stdio.h> 
#include<math.h>
int main()
{double a,b,c,d,delta,root1,root2;
printf("���������������ϵ����һ����ϵ���������\n");
scanf("%lf%lf%lf",&a,&b,&c);
d=-b/(2*a);delta=pow(b,2)-4*a*c;
if(a==0)
{
printf("������ϵ������Ϊ0!");
return 0; 
}
if(delta==0)        
    {
	printf("�÷�����������ͬ�ĸ�%lf",d);
	}
	else if(delta>0)
	    {
	    root1=d+sqrt(delta)/(2*a);root2=d-sqrt(delta)/(2*a);
	    printf("�÷�����������ͬ�����ֱ�Ϊ%lf��%lf",root1,root2);
	    return 0;
		}
		else
		{
		root1=sqrt(abs(delta))/(2*a);
		root2=sqrt(abs(delta))/(2*a);
		printf("�÷�������������������ֱ�Ϊ%lf+i%lf��%lf-i%lf",d,root1,d,root2);
		}                                                     
return 0;
}
