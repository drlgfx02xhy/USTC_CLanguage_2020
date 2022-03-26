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
	printf("������ѧ����ѧ��:\n");
	scanf("%d",&num);
	while(num)
	{
		p=(struct Student *)malloc(sizeof(struct Student));
		p->code=num;
		p->next=head;
		head=p;
		printf("������ѧ��Ϊ%d��ѧ������Ϣ������/�Ա�(m/f)/����/����:\n",num);
		scanf("%s %c %d %f",p->name,&p->sex,&p->age,&p->score); 
		printf("��������һ��ѧ����ѧ��(ѧ��Ϊ0ʱֹͣ¼��):\n");
		scanf("%d",&num); 
	}
	return head;
}

struct Student *createtail()
{
	struct Student *p,*head,*tail;
	int num;
	printf("������ѧ����ѧ��:\n");
	scanf("%d",&num);
	head=tail=NULL;
	while(num)
	{
		p=(struct Student *)malloc(sizeof(struct Student));
		p->next=NULL;
		p->code=num;
		printf("������ѧ��Ϊ%d��ѧ������Ϣ������/�Ա�(m/f)/����/����:\n",num);
		scanf("%s %c %d %f",p->name,&p->sex,&p->age,&p->score);
		if(!head)
			head=p;
		else
			tail->next=p;
		tail=p;
		printf("��������һ��ѧ����ѧ��(ѧ��Ϊ0ʱֹͣ¼��):\n");
		scanf("%d",&num); 
	}
	return head;
}

struct Student *createnum()
{
	struct Student *head,*p,*q;
	int num,sum;
	head=NULL;
	printf("������ѧ����ѧ��:\n");
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
		printf("������ѧ��Ϊ%d��ѧ������Ϣ������/�Ա�(m/f)/����/����:\n",num);
		scanf("%s %c %d %f",p->name,&p->sex,&p->age,&p->score);
		printf("��������һ��ѧ����ѧ��(ѧ��Ϊ0ʱֹͣ¼��):\n");
		scanf("%d",&num); 
	}
	return head;
}

struct Student *createfile()
{
	
	FILE *fp;
	while(!(fp=fopen("student dat","r")))
		printf("�ļ�Ϊ�գ�");
}
struct Student *create()
{
	int select;
	printf("�����봴������ķ�ʽ��\n1.ͷ�巨\n2.β�巨\n3.������ѧ����������\n4.��ѧ����Ϣ�ļ���������\n");
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
		printf("�ձ�\n");
	else
	{
		p=head;
		do{
			printf("����:%s ѧ��:%d �Ա�:%c ����:%d ����:%f\n",p->name,p->code,p->sex,p->age,p->score);
		}while(p=p->next);
	}
}

struct Student *insert(struct Student *head)
{
	struct Student *p,*q;
	int select; 
	int i,n; 
	p=(struct Student *)malloc(sizeof(struct Student));
	printf("��ѡ��1.��ָ��λ����� 2.�����������в���:\n");
	scanf("%d",&select);
	printf("������ѧ����Ϣ��ѧ��/����/�Ա�(m/f)/����/����:\n");
	scanf("%d %s %c %d %f",&p->code,p->name,&p->sex,&p->age,&p->score);
	switch(select)
	{
		case 1:printf("���뵽�ڼ����ڵ�֮��(0��Ϊ���ڿ�ͷ):\n");
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
	printf("��ѡ��:1.ɾ��ָ��λ�õļ�¼ 2.ɾ��ָ��ѧ�ŵļ�¼\n");
	scanf("%d",&select);
	switch(select)
	{
		case 1:printf("��Ҫɾ���ڼ����ڵ�:\n");
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
		case 2:printf("��Ҫɾ����ѧ��:\n");
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
	printf("��������Ҫ���ҵ�ѧ��ѧ��:\n");
	scanf("%d",&n);
	while(p->code!=n)
		p=p->next;
	if(p)
		printf("ѧ��:%d ����:%s �Ա�:%c ����:%d �ɼ�:%f\n",p->code,p->name,p->sex,p->age,p->score);
	else
		printf("δ�ҵ�������Ϣ\n"); 
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
		printf("�ձ��޷�ͳ��\n");
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
		printf("ƽ���ɼ�Ϊ:%f ��߷�Ϊ:%f\n",ave,max);
	}
}

int failsum(struct Student *head)
{
	int sum=0;
	if(!head)
		printf("�ձ�!\n");
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
		printf("�ձ���������\n");
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
			printf("������\n");
		return head;
	}
}


void w(struct Student *head)
{
	FILE *fp;
	struct Student *p;
	if(!head)
		printf("�հ�д��\n");
	else
	{
		fp=fopen("student dat","w");
		p=head;
		do{
		fprintf(fp,"ѧ��:%d ����:%s �Ա�:%c ����:%d �ɼ�:%f\n",p->code,p->name,p->sex,p->age,p->score);
		p=p->next;
		}while(p);
		printf("�ɹ�д��\n");
		fclose(fp); 
	}
}

void wplus(struct Student *head)
{
	FILE *fp;
	struct Student *p;
	if(!head)
		printf("�հ�д��\n");
	else
	{
		fp=fopen("student dat","a");
		p=head;
		do{
		fprintf(fp,"ѧ��:%d ����:%s �Ա�:%c ����:%d �ɼ�:%f\n",p->code,p->name,p->sex,p->age,p->score);
		p=p->next;
		}while(p);
		printf("�ɹ�д��\n");
		fclose(fp);
	}
}

void destroyfile()
{
	FILE *fp;
	fp=fopen("student dat","w");
	fprintf(fp,"�������ļ�");
	printf("������ļ�\n");
	fclose(fp);
}

int main()
{
	int order,order6,order8;
	struct Student *head;
	head=NULL;
	for(;;)
	{
	printf("**********�ַ���������**********\n"); 
	printf("0.�˳�����               1.����ѧ����¼����\n");
	printf("2.��ӡȫ��ѧ����¼       3.����һ���µ�ѧ����Ϣ\n");
	printf("4.������ɾ��һ��ѧ����¼ 5.��ѧ�Ų���ѧ����¼\n");
	printf("6.ͳ��                   7.����ѧ������\n");
	printf("8.������д������ļ�\n");
	printf("����������Ҫʹ�õĹ��ܣ�");
	scanf("%d",&order);
	switch(order)
	{
		case 0:return 0;
		case 1:head=create();break;
		case 2:printnode(head);break;
		case 3:head=insert(head);break;
		case 4:head=cancel(head);break;
		case 5:search(head);break;
		case 6:printf("��ѡ��ͳ�ƶ���:1.ѧ������ 2.ѧ��ƽ���ɼ�����߷� 3.����������\n");
				scanf("%d",&order6);
				switch(order6)
				{
					case 1:printf("ѧ������Ϊ:%d\n",sumpeople(head));break;
					case 2:aveandmax(head);break;
					case 3:printf("����������Ϊ:%d\n",failsum(head));break;
				}
				break;
		case 7:head=destroy(head);break;
		case 8:printf("��ѡ���ļ�д�뷽ʽ:1.��д 2.׷�� 3.���\n");
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
 
//��ʼʱ�ڽ���insert��cancel��destroy����ʱû�з���headֵ 
//�ǵ�fclose
//while�жϲ���������������һ���������ֱ������ 
