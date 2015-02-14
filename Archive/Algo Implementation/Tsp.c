// Travelling salesman problem: Using Recursion
#include<stdio.h>
#include<stdlib.h>
int n;
int g(int i,int s,int cost[100][100],int S[])
{
	int j,min,k,newS[100],select;	
	for(j=1;j<=n;j++)
		newS[j]=S[j];
	newS[i]=0;	//Since j doesn't belong to S, i is the j in previous iteration
	if(s==0)
		return cost[i][1];	//Base condition, g(i,0)=c[i][1]
	min = 999;
	for(k=0,j=2;k<s;j++)
		if(newS[j])
		{	
			select=cost[i][j]+g(j,s-1,cost,newS);//Calculatin c[i][j]+g(j,s)
			if(select<min)
				min=select;
			k++;
		}
	//Calculate minimum of c[i][j]+g(j,s)	
	return min;
}
void main()
{
	int cost[100][100],i,j,S[100];
	
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	printf("enter the cost adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			S[i]=1;				//Initially travelling hasn't started, so all vertices can be visited
		}

	printf("\n\n%d is the min \n",g(1,n-1,cost,S));	//Initial Call g(1,v-{1})
}

