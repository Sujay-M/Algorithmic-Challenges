#include<iostream>
using namespace std;int main(){	int n,i,t,j;double sum[100];cin>>t;for(i=0;i<t;i++){cin>>n;sum[t]=0;for(j=0;j<n;j++){if(j%2==0)sum[t]+=1/(2*j+1);else sum[t]-=1/(2*j+1);}}for(i=0;i<t;i++)cout<<sum[i]<<endl;return 0;}
