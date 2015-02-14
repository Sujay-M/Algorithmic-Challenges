#include<stdio.h>
#include<omp.h>
#include<sys/time.h>
void warshall(int a[100][100],int t[100][100],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			t[i][j]=a[i][j];
	#pragma omp parallel for
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if((t[i][k]+t[k][j])<t[i][j])
						t[i][j]=t[i][k]+t[k][j];
}
void main()
{
	struct timeval t;
	double start,end;
	int a[100][100],t[100][100],n,i,j;
	printf("enter n\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	gettimeofday(&t,NULL);
	start = t.tv_sec+(t.tv_usec/100000.0);
	warshall(a,t,n);
	gettimeofday(&t,NULL);
	end = t.tv_sec+(t.tv_usec/100000.0);
	printf("transitive closure is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d  ",t[i][j]);
		printf("\n");
	}
	printf("time %lf\n",(end-start));
}
