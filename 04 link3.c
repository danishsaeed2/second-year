#include<stdio.h>
#include<stdlib.h>

void find (int);

struct node
{
	int nodeid;
	struct node *up;
	struct node *right;
	struct node *down;
	struct node *left;
} *n[16];

int list[500];
int i=0;
int flag[16];

void main ()
{
	int x;
	int j,k;
	
	n[0]=(struct node *)malloc(sizeof(struct node));
	n[1]=(struct node *)malloc(sizeof(struct node));
	n[2]=(struct node *)malloc(sizeof(struct node));
	n[3]=(struct node *)malloc(sizeof(struct node));
	n[4]=(struct node *)malloc(sizeof(struct node));
	n[5]=(struct node *)malloc(sizeof(struct node));
	n[6]=(struct node *)malloc(sizeof(struct node));
	n[7]=(struct node *)malloc(sizeof(struct node));
	n[8]=(struct node *)malloc(sizeof(struct node));
	n[9]=(struct node *)malloc(sizeof(struct node));
	n[10]=(struct node *)malloc(sizeof(struct node));
	n[11]=(struct node *)malloc(sizeof(struct node));
	n[12]=(struct node *)malloc(sizeof(struct node));
	n[13]=(struct node *)malloc(sizeof(struct node));
	n[14]=(struct node *)malloc(sizeof(struct node));
	n[15]=(struct node *)malloc(sizeof(struct node));
	
	n[0]->nodeid=0;
	n[0]->up=NULL;
	n[0]->right=n[1];
	n[0]->down=NULL;
	n[0]->left=NULL;
	
	n[1]->nodeid=1;
	n[1]->up=NULL;
	n[1]->right=NULL;
	n[1]->down=n[5];
	n[1]->left=NULL;
	
	n[2]->nodeid=2;
	n[2]->up=NULL;
	n[2]->right=NULL;
	n[2]->down=NULL;
	n[2]->left=NULL;
	
	n[3]->nodeid=3;
	n[3]->up=NULL;
	n[3]->right=NULL;
	n[3]->down=NULL;
	n[3]->left=NULL;
	
	n[4]->nodeid=4;
	n[4]->up=NULL;
	n[4]->right=NULL;
	n[4]->down=n[8];
	n[4]->left=NULL;
	
	n[5]->nodeid=5;
	n[5]->up=NULL;
	n[5]->right=n[6];
	n[5]->down=n[9];
	n[5]->left=n[4];
	
	n[6]->nodeid=6;
	n[6]->up=NULL;
	n[6]->right=n[7];
	n[6]->down=n[10];
	n[6]->left=NULL;
	
	n[7]->nodeid=7;
	n[7]->up=NULL;
	n[7]->right=NULL;
	n[7]->down=NULL;
	n[7]->left=NULL;
	
	n[8]->nodeid=8;
	n[8]->up=NULL;
	n[8]->right=n[9];
	n[8]->down=n[12];
	n[8]->left=NULL;
	
	n[9]->nodeid=9;
	n[9]->up=NULL;
	n[9]->right=NULL;
	n[9]->down=n[13];
	n[9]->left=NULL;
	
	n[10]->nodeid=10;
	n[10]->up=NULL;
	n[10]->right=NULL;
	n[10]->down=n[14];
	n[10]->left=NULL;
	
	n[11]->nodeid=11;
	n[11]->up=NULL;
	n[11]->right=NULL;
	n[11]->down=NULL;
	n[11]->left=NULL;
	
	n[12]->nodeid=12;
	n[12]->up=NULL;
	n[12]->right=n[13];
	n[12]->down=NULL;
	n[12]->left=NULL;
	
	n[13]->nodeid=13;
	n[13]->up=NULL;
	n[13]->right=n[14];
	n[13]->down=NULL;
	n[13]->left=NULL;
	
	n[14]->nodeid=14;
	n[14]->up=NULL;
	n[14]->right=n[15];
	n[14]->down=NULL;
	n[14]->left=NULL;
	
	n[15]->nodeid=15;
	n[15]->up=NULL;
	n[15]->right=NULL;
	n[15]->down=NULL;
	n[15]->left=NULL;
	
	printf("\nEnter Node ID: ");
	scanf("%d",&x);
	
	for (k=0;k<16;k++)
	{
		flag[k]=0;
	}
	
	list[0]=x;
	find (x);
	
	if (list[0]==16)
		{
			printf("No nodes can be reached.\n\n");
		}
	else
	{
		printf("The following nodes can be reached: \n");
		for (j=0;list[j]!=16;j++)
		{
			if (flag[list[j]]!=1)
			{
				printf(" %d\n",list[j]);
				flag[list[j]]=1;
			}
		}
	}
}

void find (int id)
{
	do
	{	
		if (n[id]->up!=NULL)
		{
			list[i]=n[id]->up->nodeid;
			i++;
			find(n[id]->up->nodeid);
		}
		
		if (n[id]->right!=NULL)
		{
			list[i]=n[id]->right->nodeid;
			i++;
			find(n[id]->right->nodeid);
		}
		
		if (n[id]->down!=NULL)
		{
			list[i]=n[id]->down->nodeid;
			i++;
			find(n[id]->down->nodeid);
		}
		
		if (n[id]->left!=NULL)
		{
			list[i]=n[id]->left->nodeid;
			i++;
			find(n[id]->left->nodeid);
		}
		if ((n[id]->up==NULL)&&(n[id]->right==NULL)&&(n[id]->down==NULL)&&(n[id]->left==NULL))
		{
			list[i]=16;
		}
	
	} while (list[i]!=16);
	
}
