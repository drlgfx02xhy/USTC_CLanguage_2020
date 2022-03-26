#include<stdio.h>
#define N 10

struct Date{
	int year;
	int month;
	int day;
};
struct Book{
	int bnum;
	struct Date pubday;
	char bname[20];
	char author[20];
	char publish[20];
	int price;
};

void read(struct Book *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Please input :Book number,Book name,Author name,Publisher name,Price,Publish Date(year,month,day)\n");
		scanf("%d%s%s%s%d%d%d%d",&p[i].bnum,p[i].bname,p[i].author,p[i].publish,&p[i].price,&p[i].pubday.year,&p[i].pubday.month,&p[i].pubday.day);
	}
}

void print(struct Book *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{ 
		printf("Book No.%d:\nName:%s\nAuthor:%s\nPublisher:%s\nPrice:%d\nPublish date is:%d.%d.%d\n\n",p[i].bnum,p[i].bname,p[i].author,p[i].publish,p[i].price,p[i].pubday.year,p[i].pubday.month,p[i].pubday.day);
	}
}

void sort(struct Book *p,int n)
{
	struct Book temp;
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(p[j].bnum<p[k].bnum)
				k=j;
		temp=p[k];
		p[k]=p[i];
		p[i]=temp;
	}
}

void main()
{
	struct Book lib[N];
	read(lib,N);
	sort(lib,N);
	print(lib,N);
}

