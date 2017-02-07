#include<iostream>
using namespace std;

void display(struct node *, int);
int addelement(struct node *, int);
int deleteelement(struct node *, int);
int menu1();

struct node
{
	int data;
	struct node *next;
};

int main()
{
	char cmain,c;
	int total=0,n,i=0,c1=0,c2=0;
	struct node *curr=NULL;
	struct node *temp=NULL;
	struct node *firstnode=NULL;
	struct node *temp1=NULL;

	do
	{
		while (1)
		{
			cout<<"\nCreate a linked list"<<endl
				<<"1. Linear Linked List"<<endl
				<<"2. Circular Linked List"<<endl
				<<"3. Exit Menu"<<endl<<endl;
			cin>>c1;
			
			if (c1==1)
			{
				cout<<"\nCreate a linear linked list:\n\n";
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
						total=addelement(firstnode,total);
					}
					else if (c2==3)
					{
						total=deleteelement(firstnode,total);
					}
					else if (c2==4)
					{break;}
					else
					{continue;}
				}
			}
			
			else if (c1==2)
			{
				cout<<"\nCreate a circular linked list:\n\n";
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
						total=addelement(firstnode,total);
					}
					else if (c2==3)
					{
						total=deleteelement(firstnode,total);
					}
					else if (c2==4)
					{break;}
					else
					{continue;}
				}
			}
			
			else if (c1==3)
			{break;}
			
			else
			{continue;}
		}
		
		cout<<"\nCreate new linked list (y) | Exit (n) : ";
		cin>>cmain;
	}
	while (cmain=='Y'||cmain=='y');
	
	cout<<"\n\nPROGRAM TERMINATED SUCCESSFULLY\n\n";
	return 0;
}

int menu1()
{	
	int x;
	cout<<"\n\nSelect operation:"<<endl
		<<"1. Display Linked List"<<endl
		<<"2. Add element"<<endl
		<<"3. Delete element"<<endl
		<<"4. Exit Menu"<<endl<<endl;
	cin>>x;
	cout<<endl;
	return x;
}

void display (struct node *tempf, int t)
{
	int k=0;
	struct node *currf=NULL;
	while (k<t)
	{
		cout<<tempf->data<<" ";
		tempf=tempf->next;
		k++;
	}
}

int addelement (struct node *tempf, int t)
{
	int p,j=0;
	struct node *currf=NULL;
	struct node *tempf1=NULL;
	cout<<"Enter new element\n";
	cout<<"Enter at which position: ";
	cin>>p;
	if (p>t+1||p<1)
	{
		cout<<"\nError: Can't add at the entered position.";
		cout<<"\nTry Again.\n";
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
		t=t+1;
	}
	return t;
	
}

int deleteelement (struct node *tempf, int t)
{
	int p,j=0;
	struct node *currf=NULL;
	struct node *tempf1=NULL;
	cout<<"Delete element\n";
	cout<<"Which position: ";
	cin>>p;
	if (p>t||p<1)
	{
		cout<<"\nError: Node not found at entered location.";
		cout<<"\nTry Again.\n";
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
		t=t-1;
	}
	return t;
}
