#include<stdio.h>
struct Student{
	int code;
	char name[20];
	int score1,score2,score3;
	float ave;
}; 
#define N 5

void main()
{
	struct Student stu[N];
	FILE *fp;
	int i;
	fp=fopen("stud_dat","w");
	for(i=0;i<=N-1;i++)
	{
		printf("�������%d��ѧ������Ϣ:(ѧ��/����/�ɼ�1/�ɼ�2/�ɼ�3)\n",i+1);
		scanf("%d%s%d%d%d",&stu[i].code,stu[i].name,&stu[i].score1,&stu[i].score2,&stu[i].score3);
		stu[i].ave=(stu[i].score1+stu[i].score2+stu[i].score3)/3;
		fprintf(fp,"Code:%d\nName:%s\nSco1:%d\nSco2:%d\nSco3:%d\nAveS:%f\n",stu[i].code,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].ave);
	}
	fclose(fp);
}
