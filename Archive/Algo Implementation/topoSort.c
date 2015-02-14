#include<stdio.h>
void indegree(int n,int a[10][10],int ideg[])
{
	int i,j;
	for(i=0;i<n;i++)
		ideg[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j])
				ideg[j]++;
}
void toposort(int n,int cost[10][10])
{
	int ideg[10],i,top=-1,s[10],k=0,t[10],v,u;
	indegree(n,cost,ideg);
	for(i=0;i<n;i++)
		if(!ideg[i])
			s[++top]=i;
	while(top!=-1)
	{
		u=s[top--];
		t[k++]=u;
		for(v=0;v<n;v++)
			if(cost[u][v])
			{
				ideg[v]--;
				if(!ideg[v])
					s[++top]=v;
			}
	}
	printf("the topological sorting order\n");
	printf("%d ",t[0]);
	for(i=1;i<k;i++)
		printf("-> %d ",t[i]);
	printf("\n");
}
void main()
{
	int i,j,cost[10][10],n;
	printf("enter n\n");
	scanf("%d",&n);
	printf("enter the cost adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	toposort(n,cost);
}
