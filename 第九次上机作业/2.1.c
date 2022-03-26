#include<stdio.h>
#include<stdlib.h>
#define N 5
struct Student{
	int code;
	char name[20];
	int score1,score2,score3; 
	float ave;
}stu[N];
int main()
{
	int i,j,k;
	FILE *fp;
	if((fp=fopen("stud_dat","r"))==NULL)
	{
		printf("Can't open this file!\n");
		exit(0);
	}
	fseek(fp,5L,1);
	for(i=0;i<=N-1;i++)
	{
		fscanf(fp,"%d",&stu[i].code);
		fseek(fp,7L,1);//换行在windows系统中有两个字节 :\r\n 
		fscanf(fp,"%s",stu[i].name);
		fseek(fp,7L,1);
		fscanf(fp,"%d",&stu[i].score1);
		fseek(fp,7L,1);
		fscanf(fp,"%d",&stu[i].score2);
		fseek(fp,7L,1);
		fscanf(fp,"%d",&stu[i].score3);
		fseek(fp,7L,1);
		fscanf(fp,"%f",&stu[i].ave);
		fseek(fp,7L,1);
	}
	fclose(fp);
	struct Student temp;
	for(i=0;i<=N-2;i++)
	{
		k=i;
		for(j=i+1;j<=N-1;j++)
			if(stu[j].ave<=stu[k].ave)
				k=j;
		temp=stu[k];
		stu[k]=stu[i];
		stu[i]=temp;
	}
	fp=fopen("stu_sort1","w");
	for(i=0;i<=N-1;i++)
		fprintf(fp,"Code:%d\nName:%s\nSco1:%d\nSco2:%d\nSco3:%d\nAveS:%f\n",stu[i].code,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].ave);
	fclose(fp);	
	return 0;
}
