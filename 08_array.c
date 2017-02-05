#include<stdio.h>

void main ()
{
	int n;
	
	printf("\nPROGRAM START\n");
	printf("\nEnter value of square matrix to create: ");
	scanf("%d",&n);
	getchar();

	int array[n][n];
	int i=1;
	int ax=0,ay=0;
	int cx,cy;
	
	while (ax<n)
	{
		ay=0;
		while (ay<n)
		{
			array[ax][ay]=i;
			i++;
			ay++;
		}
		ax++;
	}
	
	ax=0;
	while (ax<n)
	{
		ay=0;
		while (ay<n)
		{
			printf("%d ",array[ax][ay]);
			ay++;
		}
		ax++;
	}
	printf("\n\n");
	
	i=0;
	int j=1;
	while (1)
	{
		for (cy=i;cy<=(n-i-1);cy++)
		{
			printf("%d ",array[i][cy]);
		}
		j++;
		if (j>(n*n))
		{break;}
		
		for (cx=i+1;cx<=(n-i-1);cx++)
		{
			printf("%d ",array[cx][n-i-1]);
		}
		j++;
		if (j>(n*n))
		{break;}
		
		i++;
		
		for (cy=(n-i-1);cy>=(i-1);cy--)
		{
			printf("%d ",array[n-i][cy]);
		}
		j++;
		if (j>(n*n))
		{break;}
		
		for (cx=(n-i-1);cx>=i;cx--)
		{
			printf("%d ",array[cx][i-1]);
		}
		j++;
		if (j>(n*n))
		{break;}
	}
}
