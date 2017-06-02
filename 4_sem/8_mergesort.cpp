#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void msort(int *,int,int);
void merge(int *,int,int,int);
void display();
int a[200],asize,n;

int main()
{
	int i,c;
	cout<<"\nMERGESORT ALGORITHM\n"<<endl;
	cout<<"# Select option:"<<endl 
		<<"  1 User Input"<<endl 
		<<"  2 Random Numbers"<<endl;
	cout<<"\n# ";
	cin>>c;
	
	while(true)
	{
    	if (c==1||c==2)
    	{break;}
    	else if (c==0)
    	{
	   		exit(1);
    	}
    	else
    	{
    		cout<<"\n# Invalid input! TRY AGAIN!"<<endl;
			cout<<"\n# Select option\n  1 User Input\n  2 Random Numbers\n\n# ";        	
			cin>>c;
    	}
    }
	
	cout<<endl;
	if (c==1)
	{
		i=0;
		cout<<"# Number of elements to be sorted? ";
		cin>>n;
		
		while(true)
		{
		   	if (n<=0)
		   	{	
		   		cout<<"\n# Invalid input! TRY AGAIN!"<<endl;
				cout<<"# Number of elements to be sorted? ";        	
				cin>>n;
		   	}
		   	else
		   	{break;}
		}
		
		cout<<endl;
		for (i=0;i<n;i++)
		{
			cout<<"Enter number "<<i+1<<" : ";
			cin>>a[i];
    	}
		a[i]=-1;
	}
	
	else if (c==2)
	{
		srand((int)time(0));
		cout<<"# Number of elements to be sorted? ";
		cin>>n;
		
		while(true)
		{
		   	if (n<=0)
		   	{	
		   		cout<<"\n# Invalid input! TRY AGAIN!"<<endl;
				cout<<"# Number of elements to be sorted? ";        	
				cin>>n;
		   	}
		   	else
		   	{break;}
		}
		
		for (i=0;i<n;i++)
		{
			a[i]=(rand()%200);
		}
		a[i]=-1;
	}
	
	cout<<endl;
	cout<<"Unsorted array:"<<endl;
	display();
	msort(a,0,n-1);
	cout<<"Sorted array:"<<endl;
	display();

	cout<<endl;

	return 0;
	
}

void msort(int *array,int lo,int hi)
{
	if (lo<hi)
	{
		int m;
		m=(lo+hi)/2;	//l+(r-1)/2
		
		msort(array,lo,m);
		msort(array,m+1,hi);
		merge(array,lo,m,hi);
	}
}
	
void merge(int *arr,int lo,int mid,int hi)
{
	int i,j,k;
	int temp[100];
	i=lo;
	k=lo;
	j=mid+1;
	
	while (i<=mid&&j<=hi)
	{
		if (arr[i]<arr[j])
		{
			temp[k]=arr[i];
			i++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
		}
		k++;
	}
	while (i<=mid)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	while (j<=hi)
	{
		temp[k]=arr[j];
		j++;
		k++;
	}
	
	for (i=0;i<k;i++)
	{
		arr[i]=temp[i];
	}
}

void display()
{
	int i;
	for (i=0;a[i]!=-1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl<<endl;
}
