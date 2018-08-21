// Quicksort implementation on array 
// Rename file to main class name

import java.util.Scanner;
import java.util.Random;

public class qsort
{
	public static Random r=new Random();

	public static int part(int array[],int lo,int hi) 
    {
    	int i=lo;
    	int j=hi;
        int pivot=array[(lo+hi)/2];
    	int temp;
		while (i<=j)
		{
			while (array[i]<pivot)
            {
            	i++;
            }
            while (array[j]>pivot)
            {
            	j--;
            }
            if (i<=j)
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
                i++;
                j--;
			}
		}
        return i;
    }
	
	public static void sortf(int array[],int lo,int hi)
    {
    	int x;
    	int num,i;
    	num=array.length;
       	x=part(array,lo,hi);
       			
        if (lo<x-1)
       	{
            sortf(array,lo,x-1);
       	}
        if (x<hi)
       	{
            sortf(array,x,hi);
       	}
		
    }
    
    public static void main(String[] args) 
    {
    	System.out.println("\nQUICKSORT ALGORITHM\n");
    	
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
				for (i=0;i<n;i++)
				{        
					System.out.print(array[i]+" ");
				}
				System.out.println();
			}
			else if (c==2)
			{
				for (i=0;i<n;i++)
		    	{
		    		array[i]=r.nextInt(50);
		    	}
		    	System.out.println("\nUnsorted array: ");        
				for (i=0;i<n;i++)
				{        
					System.out.print(array[i]+" ");
				}
				System.out.println();
		    }
		    
		    sortf(array,0,array.length-1);

		    System.out.println("\nElements after sorting: ");        
		    for (i=0;i<n;i++)
			{        
		        System.out.print(array[i]+" ");
		    }
		    System.out.println("\n");
		
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

