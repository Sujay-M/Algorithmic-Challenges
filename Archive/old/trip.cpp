#include<iostream>
using namespace std;
int main()
{
    int a[100][2],dupa[100][4],n,dupn,sum,pos,temp1,temp2,i,j,rep[50][2],nrep,sub,first[25],second[25],spos;
    cin>>n;
    for(i=0;i<n;i++)
    {
      cin>>a[i][0];
      dupa[i][0]=a[i][0];
      a[i][1]=dupa[i][1]=i;
      dupa[i][3]=1;
      dupa[i][2]=n-i-1;
    }
    nrep=0;
        for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[pos][0]>a[j][0]||(a[pos][0]==a[j][0] && a[pos][1]>a[j][1]))
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
            rep[nrep+1][1]=a[i][1];
            nrep+=2;
        }
        dupa[a[i][1]][2]=n-i-1;
        if(a[i][0]==a[i-1][0])
           --dupa[a[i][1]][2];
    }
    /*for(i=0;i<=nrep-1;i++)
        cout<<rep[i][0]<<" "<<rep[i][1]<<endl;*/
        for(i=0;i<n;i++)
     {
             cout<<endl<<a[i][0]<<" "<<a[i][1];
             cout<<"   "<<dupa[i][0]<<" "<<dupa[i][1]<<" "<<dupa[i][2];}
    sub=nrep/2;
    cout<<sub<<endl;
    pos=0;
    for(i=0;i<n;i++)//handling the extr ie 3rd occurance not counted
    {
      if(i<rep[pos][1] && rep[pos][0]>dupa[i][0])
            dupa[i][2]-=sub;
      else if(i==rep[pos][1])
      {
          dupa[i][2]-=(sub);
          pos+=2;
          sub--;

      }
    }
    for(i=0;i<n;i++)
     {
             cout<<endl<<a[i][0]<<" "<<a[i][1];
             cout<<"   "<<dupa[i][0]<<" "<<dupa[i][1]<<" "<<dupa[i][2];}

    sum=0;dupn=n;
    for(i=0;i<n-2;i++)//should handle 2 more cases of duplicates
    {

            dupa[a[i][1]][3]=0;
            for(j=a[i][1]+1;j<dupn;j++)
            {
                if(dupa[j][3])
                    sum+=dupa[j][2];

            }
            dupn--;

    }

    cout<<sum;
    return 0;
}
