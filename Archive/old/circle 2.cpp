#include<iostream>
#include <math>
using namespace std;
int main()
{
    int angle;
    float i,j,x1,x2,y;


    for(angle=90;angle>=180;angle--)
    {
        x1=cos(angle);
        x2=-cos(angle);

        for(j=-1;j<=1;j+=(1/90))
         {  if((x1-j)>-0.2 && (x1-j)<0.2)
                    cout<<"*";
            else if((x2-j)>-0.2 && (x2-j)<0.2)
             cout<<"*";
             else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
