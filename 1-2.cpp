#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a1, a2, a3, c=0, s1, s2;
	cin>>a1>>a2>>a3;
	s1=a1+a2+a3;
	while(1)
	{
	    a1=a2;
	    a2=a3;
	    cin>>a3;
	    s2=a1+a2+a3;
	    if(a3==0)
            break;
		if(s2>s1)
			c++;
		s1=s2;
	}
	cout<<c;
}
