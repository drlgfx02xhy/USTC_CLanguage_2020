#include<stdio.h>
#include<stdlib.h>

struct Student{
	int code;
	char name[20];
	char sex;
	int age;
	float score;
	struct Student *next;
};

struct Student *createhead()
{
	struct Student *head,*p;
	int num;
	head=NULL;
	printf("请输入学生的学号:\n");
	scanf("%d",&num);
	while(num)
	{
		p=(struct Student *)malloc(sizeof(struct Student));
		p->code=num;
		p->next=head;
		head=p;
		printf("请输入学号为%d的学生的信息：姓名/性别(m/f)/年龄/分数:\n",num);
		scanf("%s %c %d %f",p->name,&p->sex,&p->age,&p->score); 
		printf("请输入下一个学生的学号(学号为0时停止录入):\n");
		scanf("%d",&num); 
	}
	return head;
}

struct Student *createtail()
{
	struct Student *p,*head,*tail;
	int num;
	printf("请输入学生的学号:\n");
	scanf("%d",&num);
	head=tail=NULL;
	while(num)
	{
		p=(struct Student *)malloc(sizeof(struct Student));
		p->next=NULL;
		p->code=num;
		printf("请输入学号为%d的学生的信息：姓名/性别(m/f)/年龄/分数:\n",num);
		scanf("%s %c %d %f",p->name,&p->sex,&p->age,&p->score);
		if(!head)
			head=p;
		else
			tail->next=p;
		tail=p;
		printf("请输入下一个学生的学号(学号为0时停止录入):\n");
		scanf("%d",&num); 
	}
	return head;
}

struct Student *createnum()
{
	struct Student *head,*p,*q;
	int num,sum;
	head=NULL;
	printf("请输入学生的学号:\n");
	scanf("%d",&num);
	while(num)
	{
		p=(struct Student *)malloc(sizeof(struct Student));
		p->code=num;
		if(!head)
		{
			head=p;
			p->next=NULL;
		}
		else if(!head->next)
			{
				q=head;
				if(q->code<num)
				{
					p->next=NULL;
					q->next=p;
				}
				else
				{
					p->next=q;
					head=p;
				}
			}
			else
			{
				q=head;
				if(q->code>num)
				{
					p->next=q;
					head=p;
				}
				else
				{
					while(q->next&&q->next->code<num)
						q=q->next;
					p->next=q->next;
					q->next=p;
				}
			}
		printf("请输入学号为%d的学生的信息：姓名/性别(m/f)/年龄/分数:\n",num);
		scanf("%s %c %d %f",p->name,&p->sex,&p->age,&p->score);
		printf("请输入下一个学生的学号(学号为0时停止录入):\n");
		scanf("%d",&num); 
	}
	return head;
}

struct Student *createfile()
{
	
	FILE *fp;
	while(!(fp=fopen("student dat","r")))
		printf("文件为空！");
}
struct Student *create()
{
	int select;
	printf("请输入创建链表的方式：\n1.头插法\n2.尾插法\n3.创建按学号有序链表\n4.打开学生信息文件创建链表\n");
	scanf("%d",&select);
	switch(select)
	{
		case 1:createhead();break;
		case 2:createtail();break;
		case 3:createnum();break;
		case 4:createfile();break;
	}
}

void printnode(struct Student *head)
{
	struct Student *p;
	if(!head)
		printf("空表！\n");
	else
	{
		p=head;
		do{
			printf("姓名:%s 学号:%d 性别:%c 年龄:%d 分数:%f\n",p->name,p->code,p->sex,p->age,p->score);
		}while(p=p->next);
	}
}

struct Student *insert(struct Student *head)
{
	struct Student *p,*q;
	int select; 
	int i,n; 
	p=(struct Student *)malloc(sizeof(struct Student));
	printf("请选择：1.在指定位序插入 2.在有序链表中插入:\n");
	scanf("%d",&select);
	printf("请输入学生信息：学号/姓名/性别(m/f)/年龄/分数:\n");
	scanf("%d %s %c %d %f",&p->code,p->name,&p->sex,&p->age,&p->score);
	switch(select)
	{
		case 1:printf("插入到第几个节点之后(0即为插在开头):\n");
				scanf("%d",&n);
				if(!n)
				{
					p->next=head;
					head=p;
				}
				else
				{
					q=head;
					for(i=1;i<=n-1;i++)
						q=q->next;
					p->next=q->next;
					q->next=p;
				}
				break;
		case 2:	q=head;
				if(p->code<q->code)
				{
						p->next=q;
						head=p;
				}
				else
				{
					while(q->next&&q->next->code<p->code)
						q=q->next; 
					p->next=q->next;
					q->next=p;
				}
				break;
	}
	return head;
}

struct Student *cancel(struct Student *head)
{
	struct Student *p,*q;
	p=head;
	q=(struct Student *)malloc(sizeof(struct Student));
	int select;
	int i,n;
	printf("请选择:1.删除指定位置的记录 2.删除指定学号的记录\n");
	scanf("%d",&select);
	switch(select)
	{
		case 1:printf("想要删除第几个节点:\n");
				scanf("%d",&n);
				if(n==1)
				{
					q=p;
					head=p->next;
					free(q);
				}
				else
				{
					for(i=1;i<=n-2;i++)
						p=p->next;
					q=p->next;
					p->next=q->next;
					free(q);
				}
				break;
		case 2:printf("想要删除的学号:\n");
				scanf("%d",&n);
				if(p->code==n)
				{
					q=p;
					head=p->next;
					free(q);
				}
				else
				{ 
					while(p->next->code!=n)
						p=p->next;
					q=p->next;
					p->next=q->next;
					free(q);
					break;
				}
	}
	return head;
}

void search(struct Student *head)
{
	struct Student *p;
	p=head;
	int n;
	printf("请输入想要查找的学生学号:\n");
	scanf("%d",&n);
	while(p->code!=n)
		p=p->next;
	if(p)
		printf("学号:%d 姓名:%s 性别:%c 年龄:%d 成绩:%f\n",p->code,p->name,p->sex,p->age,p->score);
	else
		printf("未找到此生信息\n"); 
}

int sumpeople(struct Student *head)
{
	int i;
	struct Student *p;
	if(!head)
		return 0;
	else
		{
			i=0;
			p=head;
			while(p)
			{
				i++;
				p=p->next;
			}
			return i;
		}
}

void aveandmax(struct Student *head)
{
	int sumpeople(struct Student *head);
	float sum=0,ave,max;
	int n;
	struct Student *p;
	if(!head)
		printf("空表，无法统计\n");
	else
	{
		p=head;
		max=p->score;
		do{
			if(p->score>max)
				max=p->score;
			sum+=p->score;
		}while(p=p->next,p!=NULL);
		n=sumpeople(head);
		ave=sum/n;
		printf("平均成绩为:%f 最高分为:%f\n",ave,max);
	}
}

int failsum(struct Student *head)
{
	int sum=0;
	if(!head)
		printf("空表!\n");
	else
	{	
		struct Student *p=head;
		do{
			if(p->score<60)
				sum++;
		}while(p=p->next,p!=NULL);
		return sum;
	}
}

struct Student *destroy(struct Student *head)
{
	int sumpeople(struct Student *head);
	int i,n;
	n=sumpeople(head);
	if(!n)
		printf("空表无需销毁\n");
	else
	{
		struct Student *p;
		for(i=0;i<=n-1;i++)
		{
			p=head;
			head=p->next;
			free(p);
		}
		if(!head)
			printf("已销毁\n");
		return head;
	}
}


void w(struct Student *head)
{
	FILE *fp;
	struct Student *p;
	if(!head)
		printf("空白写入\n");
	else
	{
		fp=fopen("student dat","w");
		p=head;
		do{
		fprintf(fp,"学号:%d 姓名:%s 性别:%c 年龄:%d 成绩:%f\n",p->code,p->name,p->sex,p->age,p->score);
		p=p->next;
		}while(p);
		printf("成功写入\n");
		fclose(fp); 
	}
}

void wplus(struct Student *head)
{
	FILE *fp;
	struct Student *p;
	if(!head)
		printf("空白写入\n");
	else
	{
		fp=fopen("student dat","a");
		p=head;
		do{
		fprintf(fp,"学号:%d 姓名:%s 性别:%c 年龄:%d 成绩:%f\n",p->code,p->name,p->sex,p->age,p->score);
		p=p->next;
		}while(p);
		printf("成功写入\n");
		fclose(fp);
	}
}

void destroyfile()
{
	FILE *fp;
	fp=fopen("student dat","w");
	fprintf(fp,"已销毁文件");
	printf("已清空文件\n");
	fclose(fp);
}

int main()
{
	int order,order6,order8;
	struct Student *head;
	head=NULL;
	for(;;)
	{
	printf("**********字符串运算器**********\n"); 
	printf("0.退出程序               1.创建学生记录链表\n");
	printf("2.打印全部学生记录       3.插入一条新的学生信息\n");
	printf("4.按条件删除一条学生记录 5.按学号查找学生记录\n");
	printf("6.统计                   7.销毁学生链表\n");
	printf("8.将链表写入磁盘文件\n");
	printf("请输入您想要使用的功能：");
	scanf("%d",&order);
	switch(order)
	{
		case 0:return 0;
		case 1:head=create();break;
		case 2:printnode(head);break;
		case 3:head=insert(head);break;
		case 4:head=cancel(head);break;
		case 5:search(head);break;
		case 6:printf("请选择统计对象:1.学生人数 2.学生平均成绩和最高分 3.不及格人数\n");
				scanf("%d",&order6);
				switch(order6)
				{
					case 1:printf("学生人数为:%d\n",sumpeople(head));break;
					case 2:aveandmax(head);break;
					case 3:printf("不及格人数为:%d\n",failsum(head));break;
				}
				break;
		case 7:head=destroy(head);break;
		case 8:printf("请选择文件写入方式:1.重写 2.追加 3.清空\n");
				scanf("%d",&order8);
				switch(order8)
				{
					case 1:w(head);break;
					case 2:wplus(head);break;
					case 3:destroyfile();break;
				}
				break;
	}
	printf("\n\n");
	}
}
 
//开始时在进行insert、cancel、destroy功能时没有返回head值 
//记得fclose
//while判断并列且条件，若第一个不满足会直接跳出 
