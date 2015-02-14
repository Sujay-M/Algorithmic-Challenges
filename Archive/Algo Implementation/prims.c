#include<stdio.h>
#include<stdlib.h>
void prims(int cost[100][100],int spantree[100][2],int n)
{
	int edgeindex=0,visited[100],vselected[100],dist[100],sum=0,min,i,j,u,source;
	
	min=999;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(cost[i][j]!=0 && cost[i][j]<=min)
			{
				min=cost[i][j];
				source=i;
			}
	for(i=0;i<n;i++)
	{
		dist[i]=cost[source][i];
		visited[i]=0;
		vselected[i]=source;
	}
	visited[source]=1;
	while(edgeindex<n-1)
	{
		min=999;
		u=-1;
		for(i=0;i<n;i++)
		{
			if(visited[i]==0 && dist[i]<min)
			{
				u=i;
				min=dist[i];
			}
		}		
		spantree[edgeindex][0]=u;
		spantree[edgeindex++][1]=vselected[u];
		sum+=min;
		visited[u]=1;
		
		
		for(i=0;i<n;i++)
		{
			if(dist[i]>cost[u][i] && visited[i]==0)
			{
				dist[i]=cost[u][i];
				vselected[i]=u;
			}
		}
	}
	printf("minimal sum is %d\n ",sum);
}
void main()
{
	int cost[100][100],n,i,j,spantree[100][2];
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	printf("enter the cost adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	prims(cost,spantree,n);
	printf("spanning tree edges\n");
	for(i=0;i<n-1;i++)
		printf("%d , %d\n",spantree[i][0],spantree[i][1]);
}
