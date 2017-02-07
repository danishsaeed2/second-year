#include<iostream>
using namespace std;

void display(struct node *, int);
struct node *addelement(struct node *);
struct node *deleteelement(struct node *);
int menu1();
int total=0;

struct node
{
	int data;
	struct node *next;
};

int main()
{
	char cmain,c;
	int n,i=0,c1=0,c2=0;
	struct node *curr=NULL;
	struct node *temp=NULL;
	struct node *firstnode=NULL;
	struct node *temp1=NULL;

	do
	{
		while (1)
		{
			cout<<"\n# Create a linked list"<<endl
				<<"  1 Linear Linked List"<<endl
				<<"  2 Circular Linked List"<<endl
				<<"  3 Exit Menu"<<endl<<endl;
			cout<<"$ ";
			cin>>c1;
			
			if (c1==1)
			{
				cout<<"\n# Create a linear linked list:\n\n";
				do
				{
					curr=new node;
					cout<<"Node "<<total+1<<": ";
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

					cout<<"Enter another? ";
					cin>>c;
				}
				while (c=='Y'||c=='y');
				temp->next=NULL;
				
				while (1)
				{
					c2=menu1();
					if (c2==1)
					{
						display(firstnode,total);
					}
					else if (c2==2)
					{
						firstnode=addelement(firstnode);
					}
					else if (c2==3)
					{
						firstnode=deleteelement(firstnode);
					}
					else if (c2==4)
					{break;}
					else if (c2==0)
					{return 1;}
					else
					{continue;}
				}
			}
			
			else if (c1==2)
			{
				cout<<"\n# Create a circular linked list:\n\n";
				do
				{
					curr=new node;
					cout<<"Node "<<total+1<<": ";
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

					cout<<"Enter another? ";
					cin>>c;
				}
				while (c=='Y'||c=='y');
				temp->next=firstnode;
				
				while (1)
				{
					c2=menu1();
					if (c2==1)
					{
						display(firstnode,total);
					}
					else if (c2==2)
					{
						firstnode=addelement(firstnode);
					}
					else if (c2==3)
					{
						firstnode=deleteelement(firstnode);
					}
					else if (c2==4)
					{break;}
					else if (c2==0)
					{return 1;}
					else
					{continue;}
				}
			}
			
			else if (c1==3)
			{break;}
			
			else
			{continue;}
		}
		
		cout<<"\n# Create new linked list (y) | Exit (n): ";
		cin>>cmain;
		if (cmain=='y'||cmain=='Y')
		{
			total=0;
		}
	}
	while (cmain=='Y'||cmain=='y');
	
	cout<<"\n\nPROGRAM TERMINATED SUCCESSFULLY\n\n";
	return 0;
}

int menu1()
{	
	int x;
	cout<<"\n\n# Select operation:"<<endl
		<<"  1 Display Linked List"<<endl
		<<"  2 Add element"<<endl
		<<"  3 Delete element"<<endl
		<<"  4 Exit Menu"<<endl<<endl;
	cout<<"$ ";
	cin>>x;
	cout<<endl;
	return x;
}

void display (struct node *tempf, int t)
{
	int k=0;
	struct node *currf=NULL;
	cout<<"--- ";
	while (k<t)
	{
		cout<<tempf->data<<" ";
		tempf=tempf->next;
		k++;
	}
	cout<<"---";
}

struct node *addelement (struct node *firstf)
{
	int p,j=0;
	struct node *tempf=NULL;
	struct node *currf=NULL;
	struct node *tempf1=NULL;
	tempf=firstf;
	cout<<"# Enter element at position: ";
	cin>>p;
	if (p>total+1||p<1)
	{
		cout<<"\n# ERROR: Can't add at the entered position.";
		cout<<"\n# Try Again.\n";
	}
	else if (p==1)
	{
		currf=new node;
		currf->next=tempf;
		firstf=currf;
		cout<<"\nEnter new data: ";
		cin>>currf->data;
		total=total+1;
	}
	else
	{
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
		total=total+1;
	}
	return firstf;
}

struct node *deleteelement (struct node *firstf)
{
	int p,j=0;
	struct node *tempf=NULL;
	struct node *currf=NULL;
	struct node *tempf1=NULL;
	tempf=firstf;
	cout<<"# Delete element at position: ";
	cin>>p;
	if (p>total||p<1)
	{
		cout<<"\n# ERROR: Node not found at entered location.";
		cout<<"\n# Try Again.\n";
	}
	else if (p==1)
	{
		firstf=firstf->next;
		delete tempf;
		total=total-1;
	}
	else
	{
		j=0;
		while (j<p-2)
		{
			tempf=tempf->next;
			j++;
		}
		tempf1=tempf->next;
		tempf->next=tempf1->next;
		delete tempf1;
		total=total-1;
	}
	return firstf;
}
