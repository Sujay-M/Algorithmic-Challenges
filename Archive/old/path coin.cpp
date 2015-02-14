#include<iostream>
using namespace std;
int main()
{
    char table[51][51],n,m,k,i,j,posx,posy,count;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>table[i][j];
    count=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            if(table[i][j]=='*')
            {
                count=1;
                posx=i;posy=j;
            }
        if(count==1)
            break;
    }
    if(k<(posx+posy))
        cout<<-1;
    else
    {

    }

    return 0;
}
