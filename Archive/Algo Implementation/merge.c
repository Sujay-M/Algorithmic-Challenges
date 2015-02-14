#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>
int n;

void main()
{
	struct timeval t;
	
	void mergeSort(int,int,int*);
	int low,high,*A,i;
	double start,end;
	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);
	low=0;
	high=n-1;
	for(i=0;i<n;i++)
		//A[i]=rand()%100000;
		A[i]=n-i;
	gettimeofday(&t,NULL);
	start=t.tv_sec+(t.tv_usec/1000000.0);
	mergeSort(low,high,A);
	gettimeofday(&t,NULL);
	end=t.tv_sec+(t.tv_usec/1000000.0);
	//fin=gettime()/1000;
	
	printf("sorted numbers\n");
	for(i=0;i<n;i++)
		printf("%d\n",A[i]);
	free(A);
	printf("for n=%d time taken is %lf\n",n,(end-start));
}
void mergeSort(int low,int high, int*A)
{
	int mid;
	void merge(int,int,int,int*);
	if(low<high)
	{
		mid=(low+high)/2;
		mergeSort(mid+1,high,A);
		mergeSort(low,mid,A);
		merge(low,mid,high,A);
	}
}
void merge(int low,int mid,int high,int *A)
{
	int h=low,i=low,j=mid+1,k;
	int *B=(int*)malloc(sizeof(int)*n);
	while((h<=mid)&&(j<=high))
	{
		if(A[h]<=A[j])
		{
			B[i]=A[h];
			h++;
		}
		else
		{
			B[i]=A[j];
			j++;
		}
		i++;
	}
	if(h>mid)
		for(k=j;k<=high;k++,i++)
			B[i]=A[k];
	else
		for(k=h;k<=mid;k++,i++)
			B[i]=A[k];
	for(i=low;i<=high;i++)
		A[i]=B[i];
	free(B);
}
