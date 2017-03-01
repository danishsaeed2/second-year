// Implementation and traversals of BST

#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *right;
	struct node *left;
};
struct node *root=NULL;

class bst
{
	public:
		void insert(struct node *,struct node *);
		void ino(struct node *);
		void preo(struct node *);
		void posto(struct node *);
};

void bst::insert(struct node *tree,struct node *newn)
{
    if (root==NULL)
    {
        root=new node;
        root->data=newn->data;
        root->left=NULL;
        root->right=NULL;
        cout<<"# Root node."<<endl;
        return;
    }
    
    if (tree->data==newn->data)
    {
        cout<<"# Element already exists."<<endl;
        return;
    }
    
    if (tree->data>newn->data)
    {
        if (tree->left!=NULL)
        {
        	insert(tree->left,newn);	
		}
		else
		{
			tree->left=newn;
			(tree->left)->left=NULL;
			(tree->left)->right=NULL;
			return;
        }
    }
    
    else
    {
        if (tree->right!=NULL)
        {
            insert(tree->right,newn);
        }
        else
        {
        	tree->right = newn;
        	(tree->right)->left=NULL;
        	(tree->right)->right=NULL;
        	return;
        }	
    }
}

void bst::preo(struct node *ptr)
{
    if (root==NULL)
    {
    	cout<<"\n# Error: Tree is empty!"<<endl;
    	return;
    }
    if (ptr!=NULL)
    {
    	cout<<ptr->data<<" ";
    	preo(ptr->left);
    	preo(ptr->right);
    }
}

void bst::ino(struct node *ptr)
{
    if (root==NULL)
    {
    	cout<<"\n# Error: Tree is empty!"<<endl;
    	return;
    }
    if (ptr!=NULL)
    {
    	ino(ptr->left);
    	cout<<ptr->data<<" ";
    	ino(ptr->right);
    }
}

void bst::posto(struct node *ptr)
{
    if (root==NULL)
    {
        cout<<"\n# Error: Tree is empty!"<<endl;
        return;
    }
    if (ptr!=NULL)
    {
        posto(ptr->left);
        posto(ptr->right);
        cout<<ptr->data<<" ";
    }
}

int main()
{
	int c;
	bst b;
	struct node *temp;
	while (1)
	{
        cout<<"\n# Menu:"<<endl
			<<"  1 Insert Element "<<endl
        	<<"  2 Inorder"<<endl
        	<<"  3 Preorder"<<endl
        	<<"  4 Postorder"<<endl
        	<<"  5 Exit"<<endl;
        cout<<"\n# ";
        cin>>c;
        switch(c)
        {
        	case 1:
        		temp=new node;
            	cout<<"\nEnter data: ";
	    		cin>>temp->data;
				b.insert(root,temp);
				break;
            case 2:
            	cout<<"\nInorder Traversal: ";
            	b.ino(root);
	            cout<<endl;
    	        break;
    	    case 3:
            	cout<<"\nPreorder Traversal: ";
            	b.preo(root);
	            cout<<endl;
    	        break;
    	    case 4:
            	cout<<"\nPostorder Traversal: ";
            	b.posto(root);
	            cout<<endl;
    	        break;
    	    case 5:
            	exit(1);
        	default:
	           	cout<<"\n# Try again!"<<endl;
        }
	}
	
	return 0;
}
