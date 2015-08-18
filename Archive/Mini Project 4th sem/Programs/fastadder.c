//PROGRAM TO SIMULATE CARRY LOOK AHEAD ADDER
//Authors: Musaddiq Faraz, Sameer Shaik, Shashi Kiran Reddy, Sujay
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<omp.h>
#include<sys/time.h>

inline void terminate()						//Terminates the program if the given inputs are wrong
{
	printf("incorrect arguments\nPROGRAM TERMINATED\n");
	exit(0);
}
void create(short int *a,char c[],int len)			//Creates the array to be computed based on the given input
{
	int i;
	for(i=len;i>0;i--)
	{
		a[i]=(short int)c[len-i] - '0';
		if(a[i]>9 || a[i]<0)
			terminate();				 
	}
	a[0]=len;
}
void display(short int* a)
{
	int i=0;
	for(i=a[0];i>0;i--)
		printf("%d",a[i]);
	printf("\n");
}
short int clal(int i, short int g[], short int p[])
{
	if(i==0)
		return 0;
	if(g[i-1])
		return 1;
	else if(p[i-1]==9)
		return clal(i-1,g,p);
	else
		return 0;

}
void addnext(short int* a,const short int* b)
{
	int max,min,i;	
	max = (a[0]>b[0])?a[0]:b[0];
	min = (a[0]<b[0])?a[0]:b[0];					
	short int *g = (short int*) malloc (sizeof(short int)*max);
	short int *p = (short int*) malloc (sizeof(short int)*max);
	short int *c = (short int*) malloc (sizeof(short int)*(max+1));
	for(i=1;i<=min;i++)			
	{
		g[i-1] = (a[i]+b[i])/10;
		p[i-1] = (a[i]+b[i])%10;
	}
	if(a[0]==min)
		for(i=min+1;i<=max;i++)		
		{
			g[i-1] = 0;
			p[i-1] = b[i];
		}
	else
		for(i=min+1;i<=max;i++)
		{
			g[i-1] = 0;
			p[i-1] = a[i];
		}
	#pragma omp parallel for 
   		for(i=0;i<=max;i++)		
			c[i]=clal(i,g,p);
	#pragma omp parallel for 
   		for(i=1;i<=max;i++)		
			a[i]=(p[i-1]+c[i-1])%10;
	#pragma omp barrier
	if(c[i-1])
	{
		a[i]=1;
		a[0]=i;
	}
	else
		a[0]=i-1;
		
}
int main(int argc,char* argv[])
{
	short int *summand,*sum;
	int i,max;
	struct timeval t;
	double start,end; 
	if(!(argc-1))
		terminate();
	max=strlen(argv[1]);
	for(i=2;i<argc;i++)
		if(strlen(argv[i])>max)
			max=strlen(argv[i]);
	sum = (short int*) malloc(sizeof(short int)*(max+5));
	create(sum,argv[1],strlen(argv[1]));
	summand=(short int*) malloc(sizeof(short int)*strlen(argv[2]+1));
	create(summand,argv[2],strlen(argv[2]));
	gettimeofday(&t,NULL);
	start=t.tv_sec+(t.tv_usec/1000000.0);
	addnext(sum,summand);
	gettimeofday(&t,NULL);
	end=t.tv_sec+(t.tv_usec/1000000.0);
	free(summand);
	display(sum);
	free(sum);
	printf("%lf time\n",end-start);
	return 0;
}
