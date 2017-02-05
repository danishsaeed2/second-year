/* Create two linked lists and merge them together */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int number;
	struct node *next;
};

void main ()
{
	struct node *firstnode1=NULL;
	struct node *firstnode2=NULL;
	struct node *temp1=NULL;
	struct node *curr1=NULL;
	struct node *temp11=NULL;
	struct node *temp2=NULL;
	struct node *curr2=NULL;
	struct node *temp22=NULL;
	char choice='y';
	
	printf("\nENTER LINKED LIST 1\n");
	
	while (choice=='Y'||choice=='y')
	{
		curr1=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter data: ");
		scanf("%d",&curr1->number);
		getchar();
		if (temp1==NULL)
		{
			temp1=curr1;
			firstnode1=curr1;
		}
		else
		{
			temp1->next=curr1;
			temp1=curr1;
		}
	printf("\nContinue to enter data? ");
	scanf("%c",&choice);
	getchar();
	}
	printf("\nLINKED LIST 1 END\n");
	
	printf("\nENTER LINKED LIST 2\n");
	
	choice='y';
	while (choice=='Y'||choice=='y')
	{
		curr2=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter data: ");
		scanf("%d",&curr2->number);
		getchar();
		if (temp2==NULL)
		{
			temp2=curr2;
			firstnode2=curr2;
		}
		else
		{
			temp2->next=curr2;
			temp2=curr2;
		}
	printf("\nContinue to enter data? ");
	scanf("%c",&choice);
	getchar();
	}
	printf("\nLINKED LIST 2 END\n");
	
	printf("\nLinked List 1:\n");
	temp1=firstnode1;
	while (temp1!=NULL)
	{
		printf("%d\n",temp1->number);
		temp1=temp1->next;
	}
	
	printf("Linked List 2:\n");
	temp2=firstnode2;
	while (temp2!=NULL)
	{
		printf("%d\n",temp2->number);
		temp2=temp2->next;
	}
	
	temp1=firstnode1;
	temp2=firstnode2;
	while (temp1!=NULL&&temp2!=NULL)
	{
		if (temp1!=NULL||temp2!=NULL)
		{
			if (temp2!=NULL)
			{
				temp11=temp1->next;
				temp1->next=temp2;
				temp1=temp11;
			}
			if (temp1!=NULL)
			{
				temp22=temp2->next;
				temp2->next=temp1;
				temp2=temp22;
			}
		}
	}
	
	printf("FINAL:\n");
	temp1=firstnode1;
	while (temp1!=NULL)
	{
		printf("%d\n",temp1->number);
		temp1=temp1->next;
	}

}
