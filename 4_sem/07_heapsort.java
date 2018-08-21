// Heapsort implementation on array 
// Rename file to main class name

import java.util.Scanner;
import java.util.Random;

public class heapsort
{
	public static Random r=new Random();
	public static void hsort(int array[])
	{
		int n,i,temp;
		n=array.length;
		
		for (i=n/2;i>=0;i--)
		{
			heap(array,n,i);
		}
		
		for (i=n-1;i>=0;i--)
		{
			temp=array[0];
			array[0]=array[i];
			array[i]=temp;
			heap(array,i,0);
		}
	}
	
	public static void heap(int array[],int n,int i)
	{
		int l=i;
		int left=(2*i)+1;
		int right=(2*i)+2;
		int temp;
		
		if (left<n&&array[left]>array[l])
		{
			l=left;
		}
		
		if (right<n&&array[right]>array[l])
		{
			l=right;
		}
		
		if (l!=i)
		{
			temp=array[i];
			array[i]=array[l];
			array[l]=temp;
			heap(array,n,l);
		}
	}
	
	public static void print(int array[])
	{
		int i,n;
		n=array.length;
		for (i=0;i<n;i++)
		{
			System.out.print(array[i]+" ");
		}
		System.out.println();
	}
	
	public static void main(String args[])
	{		
		System.out.println("\nHEAPSORT ALGORITHM\n");
    	
        Scanner scan=new Scanner(System.in);        
        int n,i,c;
		
		while(true)
		{
		    System.out.print("# Number of elements to be sorted? ");
		    n=scan.nextInt();
		    
		    while(true)
		    {
		    	if (n<=0)
		    	{	
		    		System.out.println("\n# Invalid input! TRY AGAIN!");
					System.out.print("# Number of elements to be sorted? ");        	
					n=scan.nextInt();
		    	}
		    	else
		    	{break;}
		    }
		    
		    int array[]=new int[n];
		    
		    System.out.print("\n# Select option\n  1 User Input\n  2 Random Numbers\n");
		    System.out.print("\n# ");
		    c=scan.nextInt();
		    
		    while(true)
		    {
		    	if (c==1||c==2)
		    	{break;}
		    	else if (c==0)
		    	{
		    		System.exit(1);
		    	}
		    	else
		    	{
		    		System.out.print("\n# Invalid input! TRY AGAIN!\n");
		    		System.out.print("\n# Select option\n  1 User Input\n  2 Random Numbers\n\n# ");
		    		c=scan.nextInt();
		    	}
		    }
		    
		    if (c==1)
		    { 
		    	System.out.println("\nEnter "+ n +" elements:");
		    	System.out.println();
		    	for (i=0;i<n;i++)
		    	{
		    		System.out.print("Enter element "+(i+1)+": ");
		        	array[i]=scan.nextInt();
				}
		        System.out.println("\nUnsorted array: ");        
				print(array);
			}
			else if (c==2)
			{
				for (i=0;i<n;i++)
		    	{
		    		array[i]=r.nextInt(50);
		    	}
		    	System.out.println("\nUnsorted array: ");        
				print(array);
		    }
		    
		    hsort(array);

			System.out.println("\nElements after sorting: ");        
			print(array);
			System.out.println();
		
			int cont;
			System.out.print("Enter any number to continue. Enter 0 to exit.\n# ");
			cont=scan.nextInt();
			System.out.println();
			if (cont==0)
			{
				System.exit(1);
			}
		}           

	}
}

