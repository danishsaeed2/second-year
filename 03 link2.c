/* Input a linked list and use the entered data to create and print another linked list  */
/* Case conversion implemented */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct inputnode *nodeentry(int);
struct inputnode *nodeprint(struct inputnode *);
char *stringconvert(char *);

struct inputnode
{	
	int index;
	char name[20];
	char subject[20];
	float marks;
	struct inputnode *inputp;
};

struct outputnode
{
	char name[20];
	char subject[20];
	float marks;
	struct outputnode *outputp;
};

void main ()
{
	struct inputnode *ifirstnode=NULL;
	struct inputnode *icurr=NULL;
	struct inputnode *itemp=NULL;
	char choice;
	int i=1;
	
	do
	{
		icurr=nodeentry(i);
		if (itemp==NULL)
		{
			ifirstnode=icurr;
			itemp=icurr;
		}
		else
		{			
			itemp->inputp=icurr;
			itemp=icurr;
		}
	
		printf("\nContinue to enter data? (Y or N) ");
		scanf("%c",&choice);
		getchar();
	
		i++;
	} while (choice=='y'||choice=='Y');
	
	printf("\n--- INPUT LINKED LIST START ---\n");
	itemp=ifirstnode;
	while (itemp!=NULL)
	{
		nodeprint(itemp);
		itemp=itemp->inputp;
	}
	printf("\n--- INPUT LINKED LIST END ---\n");

	struct outputnode *ofirstnode=NULL;
	struct outputnode *otemp=NULL;
	struct outputnode *ocurr=NULL;

	ocurr=(struct outputnode *)malloc(sizeof(struct outputnode));
	otemp=ocurr;
	ofirstnode=ocurr;

	int x;

	itemp=ifirstnode;
	while (itemp!=NULL)
	{
		if (itemp==ifirstnode)
		{
			strcpy(otemp->subject,itemp->subject);
			strcpy(otemp->name,itemp->name);
			otemp->marks=itemp->marks;
		}
		else
		{
			otemp=ofirstnode;
			while (otemp!=NULL)
			{
				x=strcmp(itemp->subject,otemp->subject);
				if (x==0)
				{
					if (itemp->marks>otemp->marks)
					{
						otemp->marks=itemp->marks;
						strcpy(otemp->name,itemp->name);
					}
				}
				else
				{
					ocurr=(struct outputnode *)malloc(sizeof(struct outputnode));
					strcpy(ocurr->subject,itemp->subject);
					strcpy(ocurr->name,itemp->name);
					ocurr->marks=itemp->marks;
					otemp->outputp=ocurr;
					otemp=ocurr;
				}
			otemp=otemp->outputp;
			}
		}
		itemp=itemp->inputp;
	}

	printf("\n--- OUTPUT LINKED LIST START ---\n");

	otemp=ofirstnode;
	while (otemp!=NULL)
	{
		printf("\nSubject: %s",otemp->subject);
		printf("\nStudent Name: %s",otemp->name);
		printf("\nMarks: %.2f\n",otemp->marks);
		otemp=otemp->outputp;
	}
	
	printf("\n--- OUTPUT LINKED LIST END ---\n\n");
	
}
	
struct inputnode *nodeentry(int nodei)			/* Single Node Input */
{
	struct inputnode *ip;
	
	ip=(struct inputnode *)malloc(sizeof(struct inputnode));
	ip->index=nodei;
	printf("\nEnter Student Name: ");
	scanf("%[^\n]s",ip->name);
	getchar();
	strcpy(ip->name,stringconvert(ip->name));
	printf("Enter subject: ");
	scanf("%[^\n]s",ip->subject);
	getchar();
	strcpy(ip->subject,stringconvert(ip->subject));
	printf("Enter the marks: ");
	scanf("%f",&ip->marks);
	getchar();

	return ip;
}										/* Single Node Input */

struct inputnode *nodeprint(struct inputnode *op)	/* Single Node Output */
{
	printf("\nStudent Name: %s",op->name);
	printf("\nSubject: %s",op->subject);
	printf("\nMarks: %.2f\n",op->marks);
}													/* Single Node Output */

char * stringconvert(char *p)			/* Case Convert */
{
	int x;	
	if (p[0]>=97&&p[0]<=122)
		{p[0]=p[0]-32;}
	for (x=1;x<=strlen(p);x++)
	{		
	
		if (p[x]>=97&&p[x]<=122)
		{
			if (p[x-1]==' ')
			{
			p[x]=p[x]-32;
			}
		}
		else if (p[x]>=65&&p[x]<=90)
		{
			if (p[x-1]!=' ')
			{
			p[x]=p[x]+32;
			}
		}
	}
	return p;
}										/* Case Convert */
