#include<stdio.h>
#include<stdlib.h>
//Լɪ��
struct node{
	int num;
	struct node *next;
};

void main()
{
	struct node head,*p,*q;
	int i,j,m,n;
	printf("����������n�ͱ�������m��\n");
	scanf("%d%d",&n,&m);
	p=&head;
	for(i=1;i<=n;i++)
	{
		p->next=(struct node *)malloc(sizeof(struct node));
		p=p->next;
		p->num=i;
	}
	p->next=head.next; 
	p=head.next;
	for(i=1;i<n;i++)
	{
		for(j=2;j<m;j++)
			p=p->next;
		q=p->next;
		p->next=q->next;
		p=q->next;
		free(q); 
	}
	printf("��%d�����ڳ���\n",p->num);
}
