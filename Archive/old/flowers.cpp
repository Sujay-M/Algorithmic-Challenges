#include <iostream>
using namespace std;
int main()
{
	int n,k,c[1000],i,j,pos,temp,count,sum;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>c[i];
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(c[i]<c[j])
				pos=j;
		}
		temp=c[i];
		c[i]=c[pos];
		c[pos]=temp;
	}
	count=0;
	sum=0;
	for(i=0;i<n;i++)
	{
		if(i%k==0 && i!=0)
			count++;
		sum+=(count+1)*c[i];
	}
	cout<<sum;
	return 0;
}

