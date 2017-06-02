#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void radixsort(int *, int);
int maxn(int *, int);
void csort(int *, int, int);
void display(int *, int);

int main()
{
	int i,c,n;
	cout<<"\nRADIXSORT ALGORITHM\n"<<endl;
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
    
    cout<<"# Number of elements to be sorted? ";
	cin>>n;
	int a[n];
	cout<<endl;
	
	if (c==1)
	{
		i=0;
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
			cout<<"Enter number "<<i+1<<" : ";
			cin>>a[i];
    	}
		a[i]=-1;
		cout<<endl;
	}
	
	else if (c==2)
	{
		srand((int)time(0));
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
	
	cout<<"Unsorted array:"<<endl;
	display(a,n);
	radixsort(a,n);
	cout<<"\n\nSorted array:"<<endl;
	display(a,n);

	cout<<endl<<endl;

	return 0;
}

void radixsort(int *array, int n)
{
	int largest=maxn(array,n);
	
	int e;
	for(e=1;largest/e>0;e=e*10)
	{
		csort(array,n,e);
		cout<<endl;
		cout<<"\nPass: ";
		display(array,n);
	}
}

int maxn(int *array, int n)
{
	int m=array[0];
	for(int i=1;i<n;i++)
	{
		if (array[i]>m)
		{
			m=array[i];
		}
	}
	return m;
}

void csort(int *array, int n, int e)
{
	int temp[n];
	int count[10]={0};
	int i;
	
	for(i=0;i<n;i++)
	{
		count[(array[i]/e)%10]++;
	}
	for(i=1;i<10;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	
	for(i=n-1;i>=0;i--)
	{
		temp[count[(array[i]/e)%10]-1]=array[i];
		count[(array[i]/e)%10]--;
	}
	for(i=0;i<n;i++)
	{
		array[i]=temp[i];
	}
}

void display(int *array, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
}
