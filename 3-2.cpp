#include <bits/stdc++.h>
using namespace std;

int main()
{
	string in;
	vector<int> values, o, c;
	while(1)
	{
		cin>>in;
		long long value=0;;
		if(in=="stop")
			break;
		for(int i=0; i<12; i++)
		{
			value+=((int)(in[i]-48))*pow(2, 11-i);
		}
		values.push_back(value);
	}
	sort(values.begin(), values.end());
	o=values;
	c=values;
	int counter=1, limit=2048;
	while(o.size()!=1)
    {
        int co=0, indexlimit=-1;
        for(int i=0; i<o.size(); i++)
        {
            if(o[i]<limit)
                co++;
            else
            {
                indexlimit=i; //primo con un 1
                break;
            }
        }
        if(indexlimit==0) //sono tutti 1
        {
            limit+=pow(2, 11-counter);
            counter++;
            continue;
        }
        if(indexlimit==-1) //sono tutti 0
        {
            limit-=pow(2, 11-counter);
            counter++;
            continue;
        }
        if(co==1 && o.size()==2)
        {
            o.erase(o.begin());
            break;
        }
        if(co>o.size()/2) //ci sono più 0
        {
            if(indexlimit==o.size())
                o.erase(o.begin()+indexlimit);
            else
                o.erase(o.begin()+indexlimit, o.end());
            limit=limit-pow(2, 11-counter);
        }
        else //ci sono più 1
        {
            if(indexlimit==1)
                o.erase(o.begin()+0);
            else
                o.erase(o.begin(), o.begin()+indexlimit);
            limit=limit+pow(2, 11-counter);
        }
        counter++;
    }
    cout<<"oxigen: "<<o[0]<<endl;
    limit=2048, counter=1;
    while(c.size()!=1)
    {
        int co=0, indexlimit=-1;
        for(int i=0; i<c.size(); i++)
        {
            if(c[i]<limit)
                co++;
            else
            {
                indexlimit=i; //primo con un 1
                break;
            }
        }
        if(indexlimit==0) //sono tutti 1
        {
            limit+=pow(2, 11-counter);
            counter++;
            continue;
        }
        if(indexlimit==-1) //sono tutti 0
        {
            limit-=pow(2, 11-counter);
            counter++;
            continue;
        }
        if(co==1 && c.size()==2)
        {
            c.erase(c.begin()+1);
            break;
        }
        if(co>c.size()/2) //ci sono più 0, prendo gli 1
        {
            if(indexlimit==1)
                c.erase(c.begin());
            else
                c.erase(c.begin(), c.begin()+indexlimit);
            limit=limit+pow(2, 11-counter);
        }
        else //ci sono più 1, prendo gli 0
        {
            if(indexlimit==c.size()-1)
                c.erase(c.begin()+indexlimit);
            else
                c.erase(c.begin()+indexlimit, c.end());
            limit=limit-pow(2, 11-counter);
        }
        counter++;
    }
    cout<<"carbon: "<<c[0]<<endl;
    cout<<"result: "<<c[0]*o[0]<<endl;
}