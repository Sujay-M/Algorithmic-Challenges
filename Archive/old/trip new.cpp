#include<iostream>
using namespace std;
int main()
{
    int n,dupn,dummy[100][6],temp,i,j,k,pos,sum,pos2;
    cin>>n;
    dupn=0;

    for(i=0;i<n;i++)
    {

        cin>>temp;
        pos=dupn;
        for(j=0;j<dupn;j++)
        {
            if(dummy[j][0]>temp)
            {
                pos=j;
                break;
            }
        }
        if(temp==dummy[pos-1][0])
        {
            for(j=0;j<dupn;j++)
            {
                if(dummy[j][1]<dummy[pos-1][1])
                    dummy[j][3]--;
                else if(dummy[j][0]>temp)
                    dummy[j][3]--;
                if(dummy[j][2]<dummy[pos-1][1])
                    dummy[j][4]--;
                else if(dummy[j][0]>temp)
                    dummy[j][4]--;
            }
            dummy[pos-1][2]=i;
            dummy[pos-1][4]=n-i-1;
            dummy[pos-1][3]--;
            dummy[pos-1][5]=1;
        }
        else
        {
            pos2=dupn;
            while(pos2>=pos)
            {
                dummy[pos2+1][0]=dummy[pos2][0];
                dummy[pos2+1][1]=dummy[pos2][1];
                dummy[pos2+1][3]=dummy[pos2][3];
                dummy[pos2+1][3]--;
                pos2--;
            }
            dummy[pos][0]=temp;
            dummy[pos][1]=i;
            dummy[pos][3]=n-i-1;
            dummy[pos][5]=0;
            dupn++;
        }
    }
   /* for(i=0;i<dupn;i++)
     {
        cout<<dummy[i][0]<<"  "<<dummy[i][1]<<"  "<<dummy[i][2]<<"   "<<dummy[i][3]<<"   "<<dummy[i][4]<<endl;

     }*/
     sum=0;
     for(i=0;i<dupn-2;i++)
     {
         for(j=i+1;j<dupn-1;j++)
         {
             if(dummy[i][1]<dummy[j][1])
                sum+=dummy[j][3];
             if(dummy[i][1]<dummy[j][2] && dummy[j][5]==1 && dummy[i][1]>dummy[j][1])
                sum+=dummy[j][4];
         }
     }
     cout<<sum;

    return 0;

}
