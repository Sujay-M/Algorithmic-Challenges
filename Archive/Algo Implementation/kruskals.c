#include<stdio.h>
#include<stdlib.h>
/*void add(int n,int i,int j,int forest[])
{
	int prev,present;
	if(forest[i]<forest[j])
	{	
		prev=forest[j];
		forest[j]=forest[i];
		present=forest[i];
	}
	else
	{
		prev=forest[i];
		forest[i]=forest[j];
		present=forest[j];
	}
	for(i=0;i<n;i++)
		if(forest[i]==prev)
			forest[i]=present;
		
}*/
int find(int v,int efor[])
{
	while(efor[v]!=v)
		v=efor[v];
	return v;
}
void union1(int i,int j,int efor[])
{
	if(i<j)
		efor[j]=i;
	efor[i]=j;
}
void kruskals(int cost[100][100],int spantree[100][2],int n)
{
	int i,j,forest[100],count,sum,posi,posj,min;
	for(i=0;i<n;i++)
		forest[i]=i;
	count=0;
	sum=0;
	
	while(count<n-1)
	{		
		min=999;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(cost[i][j]!=0 && cost[i][j]<=min)
				{
					min=cost[i][j];
					posi=i;
					posj=j;
				}
		if(min==999)
			break;
		/*i=forest[posi];
		j=forest[posj];*/
		i = find(posi,forest);
		j = find(posj,forest);
		if(i!=j)
		{
			spantree[count][0]=posi;
			spantree[count++][1]=posj;
			//add(n,posi,posj,forest);
			union1(i,j,forest);
			sum+=min;
		}
		cost[posi][posj]=999;
		cost[posj][posi]=999;
	}
	if(count!=n-1)
	{
		printf("no spantree");
		exit(0);
	}
	printf("%d is the minimum\n",sum);
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
	kruskals(cost,spantree,n);
	printf("spanning tree edges\n");
	for(i=0;i<n-1;i++)
		printf("%d , %d\n",spantree[i][0],spantree[i][1]);
}
