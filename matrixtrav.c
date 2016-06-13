#include<stdio.h>


void main()
{

	int i=0,j=0,count=1,m,n,arr[20][20],x,y,z;

	printf("enter the no. of rows and columns:\n");
	scanf("%d%d",&n,&m);

	printf("Enter the elements:\n");
	for(x=0;x<n;x++)
	{	
		for(y=0;y<m;y++)
		{	
			scanf("%d",&arr[x][y]);
		}
	}
	z=m*n;
	while(count<=z)
	{

		for(;j<m-1;j++)
		{
			if(count<=z)
			{
				printf("%d\t",arr[i][j]);
				count++;
			}
		}

		for(;i<n-1;i++)
		{
			if(count<=z)
			{
				printf("%d\t",arr[i][j]);
				count++;
			}
		}

		for(;j>0;j--)
		{
			if(count<=z)
			{
				printf("%d\t",arr[i][j]);
				count++;
			}
		}

		for(;i>0;i--)
		{
			if(count<=z)
			{
				printf("%d\t",arr[i][j]);
				count++;
			}
		}
i++;
j++;
m--;
n--;
	}
}
