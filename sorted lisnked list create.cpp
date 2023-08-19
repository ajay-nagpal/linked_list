#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node * insert(struct node *start,int data)
{
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=data;
	//insert before ya in empty list
	if(start==NULL||data<start->data)
	{
		tmp->link=start;
		start=tmp;
		return start;		
	}
	//insert at end or middle
	else
	{
		struct node *p=start;
		while(p->link!=NULL&&p->link->data<data)
		p=p->link;
		tmp->link=p->link;
		p->link=tmp;
		return start;
	}
	return start;
}
void print(struct node *start)
{
	printf("linked list is\n");
	struct node *p=start;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
	}
	printf("\n");
}
void search (struct node *start,int data)
{
	struct node *p=start;
	int pos=1;
	while(p!=NULL)
	{
		if(p->data==data)
		{
			printf("found at %d pos",pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("not found\n");
}
int main()
{
	int n,i,data;
	printf("enter no of elements to create sorted list\n");
	scanf("%d",&n);
	struct node * start;
	start=NULL;
	if(n==0)
	{
		printf("empty list\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		printf("enter data\n");
		scanf("%d",&data);
		start=insert(start,data);
	}
	print(start);
	printf("enter data to search\n");
	scanf("%d",&data);
	search(start,data);
}
