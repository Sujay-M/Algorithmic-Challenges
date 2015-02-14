#include<iostream>
using namespace std;
int main()
{
	int n,k,i,a[100000],pos,j,temp,count,diff[99999],sum,duppos;
	cin>>n>>k;
	count=0;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)//sortin
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{    if(a[j]<a[pos])
			{

				pos=j;}
		}
		if(a[pos]==a[i-1] && i!=0)//removing the duplicates
		{
		    duppos=pos;
		    while(duppos!=n-1)
		    {
		        a[duppos]=a[duppos+1];
		        duppos+=1;
		    }
		    --n;
		}
		else
		{
		    temp=a[i];
            a[i]=a[pos];
            a[pos]=temp;

		}

	}

	for(i=0;i<n-1;i++)//finding difference between adjacent elements
		diff[i]=a[i+1]-a[i];

    pos=0;
    sum=0;
	for(i=0;i<n-1;i++)//conting
	{
	    if(diff[i]>k)//if diff between the adjacent num itself is greater than k then obviously it ll be greater for the lesser num
	    {
	        sum=0;
	        pos=i;
	    }
	    else
            sum=sum+diff[i];

	        if(sum==k)//got a pair
	        {
	            count++;

	            sum=sum-diff[pos];
	            pos++;
            }
            else if(sum>k)//difference between the elements got exceeded
            {
                while(sum>k)//to get differece between the num to less than k - till this num all the num before this one wll have diff greater than k
                {
                  sum=sum-diff[pos];
                  ++pos;
                }
                if(sum==k)//during the process of getting the diff less than k we may get a pair
                    count++;

            }

	}

	cout<<count;
	return 0;
}
