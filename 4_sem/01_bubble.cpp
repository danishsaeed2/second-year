// Implement bubble sort on array and find numer of swaps and comparisions

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubblesort(int *,int);
void bubblesortnt(int *,int);
void display();

int array[200];
int swaps=0;
int compare=0;
int comparent=0;
int i,j,n,flag;

int main()
{
	int c;
	cout<<endl;
	cout<<"Bubble sort:"<<endl 
		<<"1| Users input numbers"<<endl 
		<<"2| Random Numbers"<<endl;
	cin>>c;
	cout<<endl;
	if (c==1)
	{
		i=0;
		int k;
		cout<<"Numbers you want to enter: ";
		cin>>k;
		for (i=0;i<k;i++)
		{
			cout<<"Enter number "<<i+1<<" : ";
			cin>>array[i];
    	}
		n=k;
		array[i]=-1;
	}
	
	else if (c==2)
	{
		srand((int)time(0));
		cout<<"Number of random numbers: ";
		cin>>n;
		for (i=0;i<n;i++)
		{
			array[i]=(rand()%200);
		}
		array[i]=-1;
	}
	
	cout<<endl;
	display();
	bubblesort(array,n);
	display();
	bubblesortnt(array,n);
	cout<<"Number of swaps in early terminating bubble sort: "<<swaps<<endl;
	cout<<"Number of comparisons in early terminating bubble sort: "<<compare<<endl;
	cout<<"Number of comparisons: "<<comparent<<endl;
	cout<<endl;

	return 0;
}

void bubblesort(int *a,int l)
{
	int t;
	for (i=0;i<l;i++)
	{
		flag=0;
		for (j=0;j<l-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=0;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				flag=1;
				swaps++;
			}
			compare++;
		}
		if (flag!=1)
		{
			break;
		}
	}
}

void bubblesortnt(int *a,int l)
{
	int t;
	for (i=0;i<l;i++)
	{
		for (j=0;j<l-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=0;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			comparent++;
		}
	}
}

void display()
{
	for (i=0;array[i]!=-1;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl<<endl;
}
