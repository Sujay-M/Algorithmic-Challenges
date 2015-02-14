#include<iostream>
using namespace std;
int binary(int sn,int n2,int check1[])
{
    int start,end,mid;
    start=0;
	end=n2-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(sn<check1[mid])
            end=mid-1;
        else if(sn>check1[mid])
            start=mid+1;
        else
        {
            return mid;
        }
    }
    return n2;
}
int main()
{

    int n,a[100000][2],check2[100000],rep[50000][2],nrep,ncheck2,i,j,check[100000],ncheck,temp,pos,sum,dupcheck[100000],position,ndupcheck;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i][0];
        a[i][1]=i+1;
        check2[i]=check[i]=i+1;
    }
    nrep=0;ncheck=n;ncheck2=n;
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[pos][0]>a[j][0])
                pos=j;
        }
        temp=a[i][0];
        a[i][0]=a[pos][0];
        a[pos][0]=temp;
        temp=a[i][1];
        a[i][1]=a[pos][1];
        a[pos][1]=temp;
        if(a[i][0]==a[i-1][0])
        {
            rep[nrep][0]=a[i-1][0];
            rep[nrep+1][0]=a[i][0];
            rep[nrep][1]=a[i-1][1];
            rep[nrep+1][1]=a[i-1][1];
            nrep+=2;
        }

    }

    for(i=0;i<nrep;i+=2)
    {
        position=binary(rep[i][1],ncheck2,check2);
        if(position!=ncheck2)
        {
                while(position<ncheck2)
                check2[position]=check2[++position];
                ncheck2--;
        }
    }

    for(i=0;i<ncheck2;i++)
        cout<<check2[i]<<endl;

    sum=0;
    for(i=0;i<n-2;i++)
    {
       if(a[i][0]!=a[i-1][0])
        {


            position=binary(a[i][1],ncheck2,check2);//can remove
             if(position!=ncheck2)
             {
                 while(position<ncheck2)
                    check2[position]=check2[++position];
                 ncheck2--;
             }

            for(j=0;j<ncheck2;j++)
                dupcheck[j]=check2[j];
            ndupcheck=ncheck2;
            for(j=i+1;j<n-1;j++)
            {
                if(i>3 && a[j][0]==a[j-1][0] && a[j-1][1]<a[i][1])
                {
                    position=binary(a[j][1],ncheck2,check2);
                    sum+=ncheck2-position-1;
                    while(position<ncheck2)
                    check2[position]=check2[++position];
                    ncheck2--;
                }
                else if(a[j][0]!=a[j-1][0])
                {
                    if(a[j][0]==a[j+1][0])
                    {
                        for(position=0;position<ncheck2;position++)
                        {
                            if(check2[position]<a[j][1])
                                break;
                        }
                        sum+=ncheck2-position;
                    }
                    else
                    {
                        position=binary(a[j][1],ncheck2,check2);
                        sum+=ncheck2-position-1;
                    }
                    while(position<ncheck2)
                    check2[position]=check2[++position];
                    ncheck2--;
                }
            }
            for(j=0;j<ndupcheck;j++)
                check2[j]=dupcheck[j];
            ncheck2=ndupcheck;
        }


    }
    cout<<sum;
    return 0;
}

