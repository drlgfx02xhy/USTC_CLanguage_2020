#include<stdio.h>
#include<stdlib.h>
struct Student{
	char name[20];
	int code;
	char sex;
	float score;
	struct Student *next;
	};
struct Student *createhead()
{
	struct Student *head=NULL,*p;
	int num;
	printf("PLease input code:\n");
	scanf("%d",&num);
	while(num>0)
	{
		p=(struct Student *)malloc(sizeof(struct Student));
		p->code=num;
		printf("Please input Name/Sex/Score:\n");
		scanf("%s %c %f",p->name,&p->sex,&p->score);
		p->next=head;
		head=p;
		printf("PLease input code:\n");
		scanf("%d",&num);
	}
	return head;
}

struct Student *createtail()
{
	struct Student *head=NULL,*tail=NULL,*p;
	int num;
	printf("PLease input code:\n");
	scanf("%d",&num);
	while(num>0)
	{
		p=(struct Student *)malloc(sizeof(struct Student));
		p->next=NULL;
		p->code=num;
		if(!head)
		{
			tail=head=p;
			p->next=NULL;
		}
		printf("Please input Name/Sex/Score:\n");
		scanf("%s %c %f",p->name,&p->sex,&p->score);
		tail->next=p;
		tail=p;
		printf("PLease input code:\n");
		scanf("%d",&num);
	}
	return head;
}	

void printline(struct Student *head)
{
	struct Student *p=head;
	while(p)
	{
		printf("%d %s %c %f\n",p->code,p->name,p->sex,p->score);
		p=p->next;
	}
}

void main()
{
	struct Student *head;
	head=createhead();
	printline(head);
	getchar();
	head=createtail();
	printline(head); 
} 
