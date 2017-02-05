#include<stdio.h>
#include<stdlib.h>

void display();
void entry();
void delete();

struct node
{
	int number;
	struct node *next;
};

struct node *curr=NULL;
struct node *temp=NULL;
struct node *firstnode=NULL;
char check,next;
int a,b;

void main ()
{
	FILE *source;
	char choice,next;
	int index=0,a,b;
	
	printf("\nPROGRAM START\n");
	printf("\nEnter the Linked List:\n");

	do
	{
		curr=(struct node *)malloc(sizeof(struct node));
		index++;
		printf("\nNode %d\n",index);
		printf("Enter Value: ");
		scanf("%d",&curr->number);
		getchar();
		
		if (temp==NULL)
		{
			firstnode=curr;
			temp=curr;
		}
		else
		{
			temp->next=curr;
			temp=curr;
		}
		
		printf("Do you want to continue? ");
		scanf("%c",&choice);
		getchar();
		
	} while (choice=='y'||choice=='Y');	
	
	display();
	
	source=fopen("input.txt","r");
	if (source==NULL)
	{
		printf("\nError: Input File Missing\n");
		exit(1);
	}
	
	int i=1;
	while (1)
	{
		if (feof(source))
		{
			break;
		}
	fscanf(source,"%c %d %d\n",&check,&a,&b);
		if (check=='i')
		{
			printf("\nAfter Command %d",i);
			entry(a,b);
			display();
			i++;
		}		
		else if (check=='d')
		{
			printf("\nAfter Command %d",i);
			delete(a);
			display();
			i++;
		}
	}
}

void display()
{
	struct node *pointer=NULL;
	printf("\nThe Linked List is:\n");
	pointer=firstnode;
	while (pointer!=NULL)
	{
		printf("%d\n",pointer->number);
		pointer=pointer->next;
	}
}

void entry(int x, int y)
{
	struct node *pointer=NULL;
	struct node *previous=NULL;
	struct node *new=NULL;
	int n=1;
	pointer=firstnode;
	while (n!=x)
	{
		previous=pointer;
		pointer=pointer->next;
		n++;
	}
	new=(struct node *)malloc(sizeof(struct node));
	
		if (x==1)
		{
			new->number=y;
			new->next=pointer;
			firstnode=new;
		}
		else
		{
			new->number=y;
			previous->next=new;
			new->next=pointer;
		}
}

void delete(int x)
{
	struct node *pointer=NULL;
	struct node *previous=NULL;
	pointer=firstnode;
	while (pointer!=NULL)
	{
		if (x==pointer->number)
		{
			if (pointer==firstnode)
			{
				firstnode=pointer->next;
			}
			else
			{
				previous->next=pointer->next;
			}
			break;
		}
		previous=pointer;
		pointer=pointer->next;
	}
}
