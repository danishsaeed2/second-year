/* Creating a linked list and printing and searching in the linked list */

#include<stdio.h>
#include<stdlib.h>		/* malloc definition */
#include<string.h>

struct student	{			/* student structure */
char name[20];
int roll;
};

struct teacher	{			/* teacher structure */
int id;
char name[20];
long int mobnum;
};

union option	{			/* union */
struct student s;
struct teacher t;
};

struct node		{			/* node structure */
char c;
char id[5];
union option data;
struct node *nodepointer;	/* Node Pointer */
};

void main ()			{

	int n=0;

	struct node *firstnode=NULL;
	struct node *temp=NULL;
	struct node *curr=NULL;
	char choice='y';
	
	while (choice=='y')	{
		curr=(struct node *)malloc(sizeof(struct node));
		
		printf("\n--- NODE %d START ---\n",n+1);
		printf("\nEnter ID: ");
		scanf("%s",curr->id);
		while(1)	{
			printf("Student? (y or n) ");
			getchar();
			scanf("%c",&curr->c);
			getchar();
			if (curr->c=='y')	{
				printf("Enter Student Name: ");
				scanf("%s",curr->data.s.name);
				printf("Enter Student Roll No: ");
				scanf("%d",&curr->data.s.roll);
				break;
			}
			else if (curr->c=='n')	{
				printf("Enter Teacher ID: ");
				scanf("%d",&curr->data.t.id);
				printf("Enter Teacher Name: ");
				scanf("%s",curr->data.t.name);
				printf("Enter mobile no: ");
				scanf("%ld",&curr->data.t.mobnum);
				break;
			}
			else
				printf("\nTry Again\n");
		}
	if (temp==NULL)	{
		firstnode=curr;
		temp=curr;
	}
	else	{
	temp->nodepointer=curr;
	temp=curr;
	}
	printf("\n--- NODE %d END ---\n",n+1);
	printf("\nContinue to enter data? (y or n) ");
	getchar();
	scanf("%c",&choice);
	getchar();
	
	n++;
	}
	
	printf("\nThe number of nodes are: %d\n",n);
	
	int m;
	
	while(1)	{
		printf("\nDo you want to?\n 1) Print the linked list\n 2) Search for a node by ID\n");
		scanf("%d",&m);
		getchar();
		
		if (m==1)	{
			temp=firstnode;
			int n=0;
			while(temp!=NULL)	{
				printf("\n--- NODE %d START ---",n+1);
				printf("\nID: %s",temp->id);
				if (temp->c=='y')	{
					printf("\nStudent Name: %s",temp->data.s.name);
					printf("\nStudent Roll No: %d",temp->data.s.roll);
				}
				else if (temp->c=='n')	{
					printf("\nTeacher ID: %d",temp->data.t.id);
					printf("\nTeacher Name: %s",temp->data.t.name);
					printf("\nMobile no: %ld",temp->data.t.mobnum);
				}
				printf("\n--- NODE %d END ---\n",n+1);
				temp=temp->nodepointer;
				n++;
			}
		}
		
		else if (m==2)	{
			int i=0;
			int x;
			char key[5];
			printf("\nEnter search ID: ");
			scanf("%s",key);
			
			temp=firstnode;
			while (temp!=NULL)	{
			x=strcmp(key,temp->id);
				if (x==0)	{
					printf("\nSearch Completed.\n\nID found in node number %d",i+1);
					printf("\n\n--- NODE %d START ---",i+1);
					if (temp->c=='y')	{
						printf("\nStudent Name: %s",temp->data.s.name);
						printf("\nStudent Roll No: %d\n",temp->data.s.roll);
					}
					else if (temp->c=='n')	{
						printf("\nTeacher ID: %d",temp->data.t.id);
						printf("\nTeacher Name: %s",temp->data.t.name);
						printf("\nMobile no: %ld\n",temp->data.t.mobnum);
					}
					printf("--- NODE %d END ---\n\n",i+1);
				}
			temp=temp->nodepointer;
			i++;
			}
		}
	}
}
