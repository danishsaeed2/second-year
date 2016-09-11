/* Program to input coordinates of a diagonal of a rectangle and print the remaining coordinates and area of the
rectangle */

#include<stdio.h>
#include<stdlib.h>
#define recarea(x,y) (x)*(y)

int main (int argc(), char *argv[])	{

	printf("\nThis program does the following tasks: inputs coordinates of end points of a diagonal, find remaining coordinates of rectangle, finds area of rectangle. Using command line arguments for input and macros for area calculation.\n");
	
	float x1,x2,x3,x4,y1,y2,y3,y4,area;
	x1=atof(argv[1]);
	y1=atof(argv[2]);
	x2=atof(argv[3]);
	y2=atof(argv[4]);
	printf("\nThe coordinates of the diagonal are (%.2f,%.2f) and (%.2f,%.2f)\n",x1,y1,x2,y2);
	
	x3=x1;
	x4=x2;
	y3=y2;
	y4=y1;	
	printf("\nThe coordinates of the other two points of the rectangle are (%.2f,%.2f) and (%.2f,%.2f)\n",x3,y3,x4,y4);
	
	area=recarea((x1-x2),(y1-y2));
	
	if (area>=0)	{
	printf("\nThe area of the rectangle is %.2f \n\n",area);
	}
	else	{
	area=-area;
	printf("\nThe area of the rectangle is %.2f \n\n",area);
	}		
}
