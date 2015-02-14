#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#define max 100000
int partion (int a[],int m,int p)
{
	int v,i,j,temp;
	v=a[m];
	i=m;
	j=p;
	do
	{
		do		
		{
			i=i+1;
		}
			while(a[i]<v);
			do
			{
				j=j-1;
			}
				while(a[j]>v);

				if(i<j)
					{
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;
					}
}
						
		while(i<j);

		a[m]=a[j];
		a[j]=v;

		return j;
}
					
void quicksort(int p,int q,int *a)
{
	int j;
	if(p<q)
		{
			j=partion(a,p,q+1);
			quicksort(p,j-1,a);
			quicksort(j+1,q,a);
		}
}
void main()
{
struct timeval t;
double start,end;
	int a[max],p,q,n,i;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{
			a[i]=rand() % n;
		}
			printf("array elements are\n");
			for(i=1;i<=n;i++)
				{
					printf("%d\n",a[i]);
				}
					p=1;
					q=n;
						gettimeofday(&t,NULL);
						start=t.tv_sec+(t.tv_usec/1000000.0);
					quicksort(p,q,a);
			gettimeofday(&t,NULL);
			end=t.tv_sec+(t.tv_usec/1000000.0);
					printf("elements after sorting \n");
					for(i=1;i<=n;i++)
						{
							printf("%d\n",a[i]);
						}
printf("the elapsed time for %d elements is %f",n,(end-start));
}
