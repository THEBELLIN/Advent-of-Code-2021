#include <bits/stdc++.h>
using namespace std;

int main()
{
	string cmd;
	int n;
	int f=0, d=0, aim=0;
	while(1)
	{
		cin>>cmd>>n;
		if(cmd=="forward")
		{
			f+=n;
			d+=aim*n;
		}
		if(cmd=="up")
			aim-=n;
		if(cmd=="down")
			aim+=n;
		if(cmd=="stop")
			break;
	}
	cout<<f*d<<endl;
}