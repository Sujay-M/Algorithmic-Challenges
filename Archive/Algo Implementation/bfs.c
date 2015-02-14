#include<stdio.h>
void main()
{
	int n,i,j,v[10],g[10][10],flag,src,t[10][2],count=0;
	void bfs(int,int[],int[10][10],int,int[10][2]);
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	printf("enter the source\n");
	scanf("%d",&src);
	for(i=0;i<n;i++)
		v[i]=0;
	bfs(src,v,g,n,t);
	flag=0;
	for(i=0;i<n;i++)
		if(!v[i])
			flag=1;
		else
		{
			printf("%d is reachable\n",i);
			count++;
		}
	printf("the bfs traversal\n");
	for(i=0;i<count-1;i++)
		printf("(%d,%d)\n",t[i][0],t[i][1]);
	if(flag)
		printf("the graph is disconnected\n");
	else
		printf("the graph is connected\n");
}
void bfs(int src,int V[],int g[10][10],int n,int t[10][2])
{
	int q[10],r,f,i,u,k;
	r=f=k=0;
	q[r++]=src;
	V[src]=1;
	while(f<r)
	{
		u=q[f++];
		for(i=0;i<n;i++)
		{
			if(g[u][i]==1 && V[i]==0)
			{
				V[i]=1;
				q[r++]=i;
				t[k][0]=u;
				t[k++][1]=i;
			}
		}
	}
}
