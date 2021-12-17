#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c=0;
	cin>>a;
	while(cin>>b)
	{
		if(b>a)
			c++;
		a=b;
	}
	cout<<c;
}