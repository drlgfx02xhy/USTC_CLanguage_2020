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
	char c;
	if((fp=fopen("stud_dat","r"))==NULL)
	{
		printf("Can't open this file!\n");
		exit(0);
	}
	for(i=0;i<=N-1;i++)
	{
		while(fscanf(fp,"%c",&c),c!=':'); //从左到右执行，最后一个当作条件 
		fscanf(fp,"%d",&stu[i].code);
		while(fscanf(fp,"%c",&c),c!=':'); //说明读了东西(fscanf)以后，光标自动后移 
		fscanf(fp,"%s",stu[i].name);
		while(fscanf(fp,"%c",&c),c!=':'); 
		fscanf(fp,"%d",&stu[i].score1);
		while(fscanf(fp,"%c",&c),c!=':');
		fscanf(fp,"%d",&stu[i].score2);
		while(fscanf(fp,"%c",&c),c!=':'); 
		fscanf(fp,"%d",&stu[i].score3);
		while(fscanf(fp,"%c",&c),c!=':'); 
		fscanf(fp,"%f",&stu[i].ave);
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
	fp=fopen("stu_sort2","w");
	for(i=0;i<=N-1;i++)
		fprintf(fp,"Code:%d\nName:%s\nSco1:%d\nSco2:%d\nSco3:%d\nAveS:%f\n",stu[i].code,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].ave);
	fclose(fp);	
	return 0;
}
