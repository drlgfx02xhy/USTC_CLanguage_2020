#include<stdio.h>
#include<stdlib.h>
struct node{
	int number;
	struct node *next;
}; 

struct node *reverse(struct node *q)
{
	struct node *p;
	if(q==NULL||q->next==NULL)
		return q;
	p=reverse(q->next);
	q->next->next=q;
	q->next=NULL;
	return p;
}

void main()
{
	printf("Before reverse:\n");
	int i;
	struct node head,member[5];
	struct node *p;
	p=&head;
	for(i=0;i<=4;i++)
	{
		p->next=(struct node*)malloc(sizeof(struct node));
		p=p->next;
		p->number=i+1; 
		printf("%d\n",p->number);
	}
	p->next=NULL;
	printf("After reverse:\n");
	reverse(&head);
	while(p->next)
		{
			printf("%d\n",p->number);
			p=p->next;
		}
	free(p);
}
