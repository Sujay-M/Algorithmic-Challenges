#include<stdio.h>

void warshall(int a[100][100],int t[100][100],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			t[i][j]=a[i][j];
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(t[i][j]==0)
					if(t[i][k]==1 && t[k][j]==1)
						t[i][j]=1;
}
void main()
{
	int a[100][100],t[100][100],n,i,j;
	printf("enter n\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	warshall(a,t,n);
	printf("transitive closure is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d  ",t[i][j]);
		printf("\n");
	}
}
