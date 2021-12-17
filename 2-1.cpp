#include <bits/stdc++.h>
using namespace std;

int main()
{
	string cmd;
	int n;
	int f=0, d=0;
	while(1)
	{
		cin>>cmd>>n;
		if(cmd=="forward")
			f+=n;
		if(cmd=="up")
			d-=n;
		if(cmd=="down")
			d+=n;
		if(cmd=="stop")
			break;
	}
	cout<<f*d<<endl;
}