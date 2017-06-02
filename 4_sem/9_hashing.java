import java.util.Scanner;

class hashentry
{
	int data;
	String key;
	hashentry next;
	
	hashentry (String k, int d)
	{
		data=d;
		key=k;
		next=null;
	}
}

class hashtable
{
	private int tablesize;
	private int size;
	private hashentry[] table;
	
	public hashtable (int tsize)
	{
		size=0;
		tablesize=tsize;
		table=new hashentry[tablesize];
		
		for(int i=0;i<tablesize;i++)
		{
			table[i]=null;
		}
	}
	
	private int hashgen (String k)
	{
		
		int i,hashvalue=7,seed=113; 
		for (i=0;i<k.length();i++)
		{
			hashvalue=(hashvalue*seed)+k.charAt(i);
		}
		
		hashvalue=hashvalue%tablesize;
		if (hashvalue<0)
		{
			hashvalue=hashvalue+tablesize;
		}
		return hashvalue;
	}
	
	public void insert (String key, int data)
	{
		int hash=(hashgen(key))%tablesize;
		
		if (table[hash]==null)
		{
			table[hash]=new hashentry(key,data);
		}
		else
		{
			hashentry entry=table[hash];
			while ((entry.next!=null)&&(!entry.key.equals(key)))
			{
				entry=entry.next;
			}
			if (entry.key.equals(key))
			{
				entry.data=data;
			}
			else
			{
				entry.next=new hashentry(key,data);
			}
		}
		size++;
	}
	
	public int search (String key)
	{
		int hash=(hashgen(key))%tablesize;
		
		hashentry entry=table[hash];
		
		while ((entry!=null)&&(!entry.key.equals(key)))
		{
			entry=entry.next;
		}
		
		if (entry==null)
		{
			return -1;
		}
		else
		{
			return entry.data;
		}
	}
	
	public void remove (String key)
	{
		int hash=(hashgen(key))%tablesize;
		
		if (table[hash]!=null)
		{
			hashentry entry=table[hash];
			hashentry entry1=null;
			
			while ((entry.next!=null)&&(!entry.key.equals(key)))
			{
				entry1=entry;
				entry=entry=entry.next;
			}
			
			if (entry.key.equals(key))
			{
				if (entry1==null)
				{
					table[hash]=entry.next;
				}
				else
				{
					entry1.next=entry.next;
				}
				size--;
			}
			System.out.println("# Number removed successfully.");
		}
		else if (table[hash]==null)
		{
			System.out.println("# Error: Number not found!");
		}
	}
	
	public void printtable()
	{
		for (int i=0;i<tablesize;i++)
		{
			System.out.print("\nHash Entry "+(i+1)+" : ");
			hashentry entry=table[i];
			while (entry!=null)
			{
				System.out.print(entry.data+" ");
				entry=entry.next;
			}
		}
		System.out.print("\n");
	}
}

public class hashing
{
	public static void main (String[] args)
	{
		int c;
		Scanner scan=new Scanner(System.in);
		
		System.out.println("\nTELEPHONE DIRECTORY\n");
		System.out.print("# Enter table size: ");
		
		int s;
		while (true)
		{
			s=scan.nextInt();
			if (s!=0)
			{break;}
			else
			{System.out.println("# Invalid Input: Try Again!");
			System.out.print("\n# Enter table size: ");
			continue;}
		}
		
		hashtable h=new hashtable(s);
		while(true)
		{
			System.out.println("\n# Select Option:");
			System.out.println("  1 Insert Number");
			System.out.println("  2 Remove Number");
			System.out.println("  3 Search Number");
			System.out.println("  4 Print Table");
			System.out.println("  5 Exit");
			
			System.out.print("\n# ");
			c=scan.nextInt();
			
			if (c==1)
			{
				String x;
				System.out.print("\n# Enter name: ");
				x=scan.next();
				System.out.print("# Enter number: ");
				h.insert(x,scan.nextInt());
			}
			else if (c==2)
			{
				System.out.print("\n# Enter name: ");
				h.remove(scan.next());
			}
			else if (c==3)
			{
				System.out.print("\n# Enter name: ");
				int da=h.search(scan.next());
				if (da==-1)
				{
					System.out.println("# Error: Number not found!");
				}
				else
				{
					System.out.println("# Number: "+da);
				}
			}
			else if (c==4)
			{
				h.printtable();
			}
			else if (c==5)
			{
				System.out.println("# Successfully Terminated.");
				System.exit(1);
			}
			else
			{
				System.out.println("# Wrong Input!");
			}
		}
	}
}
