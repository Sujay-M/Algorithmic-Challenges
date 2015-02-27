#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[81],*enc;
	enc = NULL;
	cin>>str;
	int l = strlen(str),i,j,pos1,pos2;
	int r = int(floor(sqrt(l)));
	int c = int(ceil(sqrt(l)));
	if(r*c<l)
		r++;
	enc = new char[r*c+c+1];
	pos1=0;
	for(j=0;j<c;j++)
	{
		for(i=0;i<r;i++)
		{			
			pos2 = i*c+j;
			if (pos2>=l)
				break;
			enc[pos1++] = str[pos2];
			
		}
		enc[pos1++] = ' '; 
	}
	enc[pos1] = '\0';
	cout<<enc;
}