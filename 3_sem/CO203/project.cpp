#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
class parent
{
protected:
	string parent_name;
public:
  parent (){};
	parent(string s);
	virtual void display()
	{
		cout << parent_name << endl;
	};
};
parent :: parent(string s)
{
	parent_name = s;
};
class subsidiary: public parent
{
protected:
	string sub_name;
	
public:
	subsidiary(string sub);
	void additem();
	void listitem();
	void bill();
  void display()
  {
    cout <<  sub_name;
  };
};

subsidiary::subsidiary(string sub)
{
	sub_name=sub;
}

void subsidiary::additem()
{
	char choice;
	char input[30];
	ofstream fout((sub_name+".txt").c_str(),ios::app);
	if (!fout)
		{
		cout<<"Cannot v "<<(sub_name+".txt").c_str()<<endl;
		return;
		}
	cout<<"\nAdd Item? ";
	cin>>choice;
  cin.ignore(1,'\n');
	while (choice=='y'||choice=='Y')
	{
		cout<<"\nEnter Item ID: ";
		cin.getline(input,30);
		fout<<input<<"\n";
		cout<<"Enter Item Name: ";
		cin.getline(input,30);
		fout<<input<<"\n";
		cout<<"Enter Item price: ";
		cin.getline(input,30);
		fout<<input<<"\n";
		
		cout<<"\nAdd another item? ";
		cin>>choice;
    cin.ignore(1,'\n');
		fout<<"---\n";
	}
	fout.close();
}

void subsidiary::listitem()
{
	string x;
	int i=1;
	cout<<"\n";
	ifstream fin((sub_name+".txt").c_str());
	if (!fin)
	{
		cout<<"Cannot open "<<(sub_name+".txt").c_str()<<endl;
		return;
	}
	
	while (1)
	{
		getline(fin,x,'\n');
		if (fin.eof())
		{
			break;
		}
		cout<<"\nItem Number "<<i<<endl;
		cout<<x<<endl;
		getline(fin,x,'\n');
		cout<<x<<endl;
		getline(fin,x,'\n');
		cout<<x<<endl;
		fin.ignore(100,'\n');
		i++;
	}
	fin.close();
}

void subsidiary::bill()
{
	unsigned int j,k,n,total=0;
	string mob;
	string x;
	char choice;
	cout<<"\nEnter customer mobile no.: ";
	cin>>mob;
	ofstream fout((mob+".txt").c_str());
	if (!fout)
	{
		cout<<"Cannot open "<<(mob+".txt").c_str()<<endl;
		return;
	}

	do
	{
		ifstream fin((sub_name+".txt").c_str());
		if (!fin)
		{
			cout<<"Cannot open "<<(sub_name+".txt").c_str()<<endl;
			return;
		}
		cout<<"\nSelect Item\n";
		j=0;
		while (1)
		{
			fin.ignore(100,'\n');
			getline(fin,x,'\n');
			if (fin.eof())
			{
				break;
			}
			cout<<j<<".\t";
			cout<<x<<"\t";
			getline(fin,x,'\n');
			cout<<x<<endl;
			fin.ignore(100,'\n');
			j++;
		}
		fin.close();
		fin.open((sub_name+".txt").c_str());
		cin>>n;
		k=0;
		for (unsigned int k=0;k<=n;k++)
		{
			if (k==n)
			{
				fin.ignore(100,'\n');
				getline(fin,x,'\n');
				if (fin.eof())
				{
					break;
				}
				fout<<k<<".\t";
				fout<<x<<"\t";
				getline(fin,x,'\n');
				fout<<x<<endl;
				total=total+atoi(x.c_str());
				fin.ignore(100,'\n');
			}
			else
			{
				if (fin.eof())
				{
					break;
				}
				fin.ignore(100,'\n');
				fin.ignore(100,'\n');
				fin.ignore(100,'\n');
				fin.ignore(100,'\n');
			}
		}
		cout<<"\nSelect another item?";
		cin>>choice;
    cin.ignore(1,'\n');
		fin.close();
	}
	while (choice=='y'||choice=='Y');
	fout.close();
	ifstream fin((mob+".txt").c_str());
	if (!fin)
	{
		cout<<"Cannot open "<<(mob+".txt").c_str()<<endl;
		return;
	}
	cout<<"\n---Customer Bill---"<<endl;
	cout<<"Customer ID: "<<mob<<endl;
	cout<<"\nItems Purchased:"<<endl;
	while (1)
	{
		getline(fin,x,'\n');
		if (fin.eof())
		{
			break;
		}
		cout<<x<<endl;
	}
	fin.close();
	cout<<"\nAmount: "<<total<<endl;
}

int main()
{
	subsidiary sub[3]={subsidiary("Grocery Store"),subsidiary("Restaurant"),subsidiary("Gym")};
	int option[4];
	char choice;
	
	cout<<"\n-----PROGRAM START-----"<<endl;
  cout << "\t\t";
  parent company("MAMAGACHI ENTERPRISES");
  parent * bptr;
  bptr = &company;
  bptr->display();
	do
	{
		cout<<"\nSelect Option:\n"<<endl;
		cout<<"\t1. Generate Bill"<<endl
			<<"\t2. Add Item"<<endl
			<<"\t3. List Items"<<endl
			<<"\t4. Exit Program"<<endl;
		cin>>option[0];

	try
	{
  		if (option[0]==1)
  		{
  			cout<<"\nGenerate bill of:\n"<<endl;
          bptr = &sub[0];
  			  cout << "\t" << "0.";
          bptr -> display();
          cout << endl;
          bptr = &sub[1];
          cout << "\t" << "1." ;
          bptr -> display();
          cout << endl;
          bptr= &sub[2];
          cout << "\t" << "2.";
  				bptr -> display();
          cout << endl;
  			cin>>option[1];
  			if (option[1]!=0&&option[1]!=1&&option[1]!= 2)
        	{
        		throw(option[2]);
        	}
  			sub[option[1]].bill();
  		}
  		else if (option[0]==2)
  		{
  			cout<<"\nAdd Item of:"<<endl;
        bptr = &sub[0];
          cout << "\t" << "0.";
          bptr -> display();
          cout << endl;
          bptr = &sub[1];
          cout << "\t" << "1." ;
          bptr -> display();
          cout << endl;
          bptr= &sub[2];
          cout << "\t" << "2.";
          bptr -> display();
          cout << endl;
  			
  			cin>>option[2];
  			if (option[2]!=0&&option[2]!=1&&option[2]!= 2)
        	{
        		throw(option[2]);
        	}
  			sub[option[2]].additem();
  		}
  		else if (option[0]==3)
  		{
  			cout<<"\nList Items of:"<<endl;
  		  bptr = &sub[0];
          cout << "\t" << "0.";
          bptr -> display();
          cout << endl;
          bptr = &sub[1];
          cout << "\t" << "1." ;
          bptr -> display();
          cout << endl;
          bptr= &sub[2];
          cout << "\t" << "2.";
          bptr -> display();
          cout << endl;
  			cin>>option[3];
  			if (option[3]!=0&&option[3]!=1&&option[3]!= 2)
        	{
        		throw(option[2]);
        	}
  			sub[option[3]].listitem();		
  		}
  		else if (option[0]==4)
  		{
  			cout<<"\n-----PROGRAM TERMINATED-----\n\n";
  			return 0;
  		}
  		else
  		{
        	throw(option[0]);
  		}
	}
	catch(int a)
	{
		cout<<"\nError: Please select from the given options.\n";   //Exception
	}	
  		cout<<"\nReturn to main screen? ";
  		cin>>choice;
      cin.ignore(1,'\n');
	}
	while (choice=='y'||choice=='Y');
	
	cout<<"\n-----PROGRAM TERMINATED-----\n\n";
	return 0;
}
