#include<iostream>
using namespace std;
int main()
{
    int r;
    double i,j;
    cin>>r;
    for(i=r;i>=-r;i-=0.25)
    {
        for(j=-r;j<=r;j+=0.25)
        {  if((i*i + j*j - r*r)<0.15 && (i*i + j*j - r*r)>-0.15)////if((i*i + j*j - r*r)==0)
                    cout<<"*";
             cout<<"   ";
        }
        cout<<endl<<endl;
    }
    return 0;
}
