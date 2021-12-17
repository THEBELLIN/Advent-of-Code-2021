#include <bits/stdc++.h>
using namespace std;

int main()
{
	string in;
	int c=0;
	vector<int> istances (12, 0), gamma(12, 0), epsilon(12, 0);
	while(1)
	{
		cin>>in;
		if(in=="stop")
			break;
		for(int i=0; i<in.length(); i++)
		{
			if(in.at(i)=='1')
				istances[i]++;
		}
		c++;
	}
	for(int i=0;i<12; i++)
	{
		if(istances[i]>(c/2))
		{
			gamma[i]=1;
			epsilon[i]=0;
		}
		else
		{
			gamma[i]=0;
			epsilon[i]=1;
		}
	}
	long long g=0, e=0;
	for(int i=0; i<12; i++)
	{
		g+=gamma[i]*pow(2, 11-i);
		e+=epsilon[i]*pow(2, 11-i);
	}
	cout<<g*e;
}