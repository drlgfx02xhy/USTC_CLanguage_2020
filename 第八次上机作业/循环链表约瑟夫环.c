#include<stdio.h>
#include<stdlib.h>
//约瑟夫环
struct node{
	int num;
	struct node *next;
};

void main()
{
	struct node head,*p,*q;
	int i,j,m,n;
	printf("请输入人数n和报数周期m：\n");
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
	printf("第%d号仍在场上\n",p->num);
}
