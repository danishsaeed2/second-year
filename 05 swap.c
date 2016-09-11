#include<stdio.h>
#include<stdlib.h>

struct node
{
	char text[20];
	struct node *pointer;
};

void main ()
{
	char choice;
	int l;
	
	struct node *firstnode=NULL;
	struct node *temp=NULL;
	struct node *curr=NULL;
	struct node *a=NULL;
	struct node *b=NULL;
	struct node *c=NULL;
	struct node *d=NULL;
	
	printf("\nEnter the linked list: \n\n");
	
	do
	{
		for (l=0;l<2;l++)
		{
			curr=(struct node *)malloc(sizeof(struct node));

			printf("Enter text: ");
			scanf("%[^\n]s",curr->text);
			getchar();
		
			if (temp==NULL)
			{
				firstnode=curr;
				temp=curr;
			}
			else
			{			
				temp->pointer=curr;
				temp=curr;
			}
		}
	
		printf("\nContinue to enter data? (Y or N) ");
		scanf("%c",&choice);
		getchar();
	
	} while (choice=='y'||choice=='Y');
	
	printf("\nThe entered linked list is: \n");
	
	temp=firstnode;
	while (temp!=NULL)
	{
		printf("%s\n",temp->text);
		temp=temp->pointer;
	}
	
	temp=firstnode;
	while (temp!=NULL)
	{
		if (a==NULL)
		{
			a=temp;
			b=temp->pointer;
			c=b->pointer;
			firstnode=b;
			a->pointer=c;
			b->pointer=a;
		}
		else
		{
			b=temp;
			c=temp->pointer;
			d=c->pointer;
			
			a->pointer=c;
			c->pointer=b;
			b->pointer=d;
		}
	a=temp;
	temp=temp->pointer;
	}
	
	printf("\nThe output linked list is: \n");
	
	temp=firstnode;
	while (temp!=NULL)
	{
		printf("%s\n",temp->text);
		temp=temp->pointer;
	}
}
