#include<stdio.h>
#include<stdlib.h>
//约瑟夫问题 

struct node{
	int num;
	struct node *next;
}; 

void main()
{
	void create(struct node *head,int n);
	void game(struct node *head,int n,int m);
	int m,n;
	struct node head;//虚拟头head 
	printf("请输入人数n和报号周期m：\n");
	scanf("%d%d",&n,&m);
	create(&head,n);
	game(&head,n,m);
}

//创建循环链表的函数 
void create(struct node *head,int n)
{
	struct node *p,*q;
	int i;
	p=head;
	for(i=1;i<=n;i++)
	{
		p->next=(struct node*)malloc(sizeof(struct node));
		p=p->next;
		p->num=i;
	}
	p->next=head->next;
} 

//进行约瑟夫环游戏的函数 
void game(struct node *head,int n,int m)
{
	int i,j;
	struct node *q,*p;
	p=head->next;
	for(i=1;i<=n-1;i++)
	{
		for(j=2;j<=m-1;j++)
			p=p->next;
		q=p->next;
		p->next=q->next;
		p=q->next;
		free(q);
	}
	printf("第%d号仍在场上",p->num);
}
