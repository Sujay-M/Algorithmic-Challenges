// Travelling salesman problem: Using Recursion
#include<stdio.h>
#include<stdlib.h>
int n;
int g(int i,int s,int cost[100][100],int vert[])
{
	int j,*select,min,k;
	int* newvert=(int*) malloc(sizeof(int)*n);		//Holds Set S
	for(j=0;j<n;j++)
		newvert[j]=vert[j];
	newvert[i]=0;						//Since j doesn't belong to S
	if(s==0)
		return cost[i][0];				//Base condition, g(i,0)=c[i][1]
	select=(int*)malloc(sizeof(int)*s);			//Contains g(j,s), to calculate minimum
	for(j=0,k=1;j<s;k++)
	{
		if(newvert[k])
		{	
			select[j]=cost[i][k]+g(k,s-1,cost,newvert);//Calculatin c[i][j]+g(j,s)
			j++;
		}
	}
	min=999;
	for(j=0;j<s;j++)
	{
		if(select[j]<min)
			min=select[j];				//Calculating Minimum
	}
	free(select);
	free(newvert);
	return min;
}
void main()
{
	int cost[100][100],i,j,vert[100];
	
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	printf("enter the cost adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			vert[i]=1;				//Initially travelling hasn't started, so all vertices can be visited
		}
	printf("\n\n%d is the min \n",g(0,n-1,cost,vert));	//Initial Call g(1,v-{1})
}

