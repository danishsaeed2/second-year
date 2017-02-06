#include<iostream>
using namespace std;

void display(struct node *);
int addelement(struct node *, int);
int deleteelement(struct node *, int);

struct node
{
	int data;
	struct node *next;
};

int main()
{
	char c;
	int total,n,i=0;
	struct node *curr=NULL;
	struct node *temp=NULL;
	struct node *firstnode=NULL;
	struct node *temp1=NULL;

	do
	{
		curr=new node;
		cout<<"Enter data in list: ";
		cin>>curr->data;
		total++;
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

		cout<<"Continue entering? ";
		cin>>c;
	}
	while (c=='Y'||c=='y');
	temp->next=NULL;

	display(firstnode);
	addelement(firstnode,total);
	display(firstnode);
}

void display (struct node *tempf)
{
	struct node *currf=NULL;
	while (tempf!=NULL)
	{
		cout<<tempf->data<<" ";
		tempf=tempf->next;
	}
}

int addelement (struct node *tempf, int t)
{
	int p,j=0;
	struct node *currf=NULL;
	struct node *tempf1=NULL;
	cout<<"\nEnter new element\n";
	cout<<"Enter at which position: ";

	cin>>p;
	j=0;
	while (j<p-2)
	{
		tempf=tempf->next;
		j++;
	}
	tempf1=tempf->next;
	currf=new node;
	tempf->next=currf;
	currf->next=tempf1;
	
	cout<<"\nEnter new data: ";
	cin>>currf->data;
	t=t+1;
	return t;
}

int deleteelement (struct node *tempf, int t)
{
	int p,j=0;
	struct node *currf=NULL;
	struct node *tempf1=NULL;
	cout<<"\nDelete element\n";
	cout<<"Which position: ";
	cin>>p;

	j=0;
	while (j<p-2)
	{
		tempf=tempf->next;
		j++;
	}
	tempf1=tempf->next;
	tempf->next=tempf1->next;
	delete temp1;
	t=t-1;
	return t;
}
