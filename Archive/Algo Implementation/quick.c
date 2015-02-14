#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

void main()
{
	void QuickSort(int*,int,int);
	struct timeval t;
	int low,high,*A,i,n;
	double start,end;
	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*(n+1));
	low=0;
	high=n;
	for(i=0;i<n;i++)
		//A[i]=rand()%100000;
		A[i]=n-i;
	A[n]=100001;
	gettimeofday(&t,NULL);
	start=t.tv_sec+(t.tv_usec/1000000.0);
	QuickSort(A,low,high);
	gettimeofday(&t,NULL);
	end=t.tv_sec+(t.tv_usec/1000000.0);
	printf("sorted numbers\n");
	for(i=0;i<n;i++)
		printf("%d\n",A[i]);
	free(A);
	printf("start =%lf end=%lf \nfor n=%d time taken is %lf\n",start,end,n,(end-start));
}
void QuickSort(int* A,int low,int high)
{
	int j;
	int Partition(int*,int,int);
	if (low<high)
	{
		j=Partition(A,low,high);
		
		QuickSort(A,low,j-1);
		QuickSort(A,j+1,high);
	}
}
int Partition(int* A,int low,int high)
{
	
	int i=low,j=high;
	int pivot=A[low];
	
	while(i<=j)
	{
		while(A[i]<=pivot)
			i++;
		while(A[j]>pivot)
			j--;
		if(i<j)
		{
			A[i]=A[i]+A[j];
			A[j]=A[i]-A[j];
			A[i]=A[i]-A[j];
		}
	}
	A[low]=A[j];
	A[j]=pivot;
	return j;
}	


