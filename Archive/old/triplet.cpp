#include<iostream>
using namespace std;
int binary(int sn,int n2,int check2[])
{
    int start,end,mid;
    start=0;
	end=n2-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(sn<check2[mid])
            end=mid-1;
        else if(sn>check2[mid])
            start=mid+1;
        else
        {
            return mid;
        }
    }
    return 0;
}
int main()
{
	int n,i,d[100000],pos[100000],ncheck,check[100000],npos,temppos,temp,j,pos2,duppos,position,sum,rep[50000][2],nrep,dpos[100000],dcheck[100000],ndpos,ndcheck;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>d[i];
	for(i=0;i<n;i++)
	{
		dcheck[i]=check[i]=i;
		dpos[i]=pos[i]=i;
	}
	ndpos=npos=n;
	ndcheck=ncheck=n;
	nrep=0;
	for(i=0;i<n;i++)
	{
		pos2=i;
		for(j=i+1;j<n;j++)
		{
			if(d[j]<d[pos2])
				pos2=j;
		}
		temp=d[i];
        d[i]=d[pos2];
        d[pos2]=temp;
		temppos=pos[i];
		pos[i]=pos[pos2];
		pos[pos2]=temppos;
        if(d[i]==d[i-1])
        {
            rep[nrep][0]=pos[i-1];
            rep[nrep][1]=pos[i];
            nrep++;
            duppos=pos[i];
            while(duppos!=ncheck)
            {
                check[duppos]=check[duppos+1];
                duppos++;
            }
            duppos=pos[i-1];
            while(duppos!=ndcheck)
            {
                dcheck[duppos]=dcheck[duppos+1];
                duppos++;
            }
            ncheck--;
            ndcheck--;
            duppos=i;
            while(duppos!=npos)
            {
                d[duppos]=d[duppos+1];
                pos[duppos]=pos[duppos+1];
                dpos[duppos-1]=dpos[duppos];
                duppos++;
            }
            ndpos--;
            npos--;
            n--;
            i--;
        }
	}
	/*for(i=0;i<n;i++)
        cout<<d[i]<<" "<<pos[i]<<" "<<check[i]<<endl; */
    sum=0;
    for(i=0;i<npos;i++)
    {
        position=binary(pos[i],ncheck,check);
        sum+=(ncheck-position-2)*(ncheck-position-1)/2;
        while(position<ncheck)
        {
            check[position]=check[position+1];
            position+=1;
        }
        ncheck--;
    }
    cout<<sum;
    return 0;
}
