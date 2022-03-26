#include<stdio.h>
#include<math.h>
struct complex{
	double real;
	double imagine;
};

void plus(struct complex x1,struct complex x2,struct complex *plusout)
{
	plusout->real=x1.real+x2.real;
	plusout->imagine=x1.imagine+x2.imagine;
}

void multiple(struct complex x1,struct complex x2,struct complex *mulout)
{
	mulout->real=x1.real*x2.real-x1.imagine*x2.imagine;
	mulout->imagine=x1.real*x2.imagine+x2.real*x1.imagine;
}

double molen(struct complex x1)
{
	double len;
	len=sqrt(x1.real*x1.real+x1.imagine*x1.imagine);
	return len; 
}

int main()
{
	struct complex x1,x2,plusout,mulout;
	double len;
	int choose;
	printf("��ѡ���ܣ�1.�ӷ� 2.�˷� 3.��ģ:\n");
	scanf("%d",&choose);
	while(choose==1)
	{
		printf("������No.1����a+ib��(����ab����)\n");
		scanf("%lf%lf",&x1.real,&x1.imagine);
		printf("������No.2����a+ib��(����ab����)\n");
		scanf("%lf%lf",&x2.real,&x2.imagine);
		plus(x1,x2,&plusout);
		printf("%lf+i%lf",plusout.real,plusout.imagine);
		return 1;
	}
	while(choose==2)
	{
		printf("������No.1����a+ib��(����ab����)\n");
		scanf("%lf%lf",&x1.real,&x1.imagine);
		printf("������No.2����a+ib��(����ab����)\n");
		scanf("%lf%lf",&x2.real,&x2.imagine);
		multiple(x1,x2,&mulout);
		printf("%lf+i%lf",mulout.real,mulout.imagine);
		return 2; 
	}
	while(choose==3)
	{
		printf("�����븴��a+ib��(����ab����)\n");
		scanf("%lf%lf",&x1.real,&x1.imagine);
		len=molen(x1);
		printf("%lf",len);
		return 3;
	}
}
