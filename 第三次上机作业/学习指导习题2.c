#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,p,S;
	printf("�����������������ߵ���ֵ��");
	scanf("%f%f%f",&a,&b,&c);
	if(a+b>c&&a+c>b&&b+c>a)
	{
		if(a==b||b==c||c==a)
		{
			if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
			printf("��������Ϊ����ֱ��������\n");
		    else if(a==b&&b==c)
		            printf("��������Ϊ�ȱ�������\n");
		        else  
		            printf("��������Ϊ����������\n");
		}
		else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
		         printf("��������Ϊֱ��������\n");
	        else 
			     printf("��������Ϊһ��������\n");
	    p=(a+b+c)/2;
	    S=sqrt(p*(p-a)*(p-b)*(p-c));
	    printf("�����������Ϊ%f\n",S);
	}
    else 
	    printf("DATA ERROR!");
}

