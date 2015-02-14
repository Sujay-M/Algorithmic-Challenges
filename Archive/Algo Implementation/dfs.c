#include<stdio.h>
void main()
{
	int n,i,j,v[10],g[10][10],flag;
	void dfs(int,int[],int[10][10],int);
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	
	for(i=0;i<n;i++)
		v[i]=0;
	dfs(0,v,g,n);
	flag=0;
	for(i=1;i<n;i++)
		if(!v[i])
			flag=1;
	if(flag)
		printf("the graph is disconnected\n");
	else
		printf("the graph is connected\n");
}
void dfs(int v,int V[],int g[10][10],int n)
{
	V[v]=1;
	int w;
	for(w=1;w<n;w++)
		if(V[w]==0 && g[v][w]==1)
			dfs(w,V,g,n);
}
