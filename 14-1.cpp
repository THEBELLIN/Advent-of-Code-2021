#include <bits/stdc++.h>
using namespace std;

vector<char> pol;
map<string, char> m;
map<char, int> occ;

int main()
{
    while(1)
    {
        char c;
        cin>>c;
        if(c=='-')
            break;
        pol.push_back(c);
    }
    while(1)
    {
        string cmd;
        cin>>cmd;
        if(cmd=="-")
            break;
        char repl;
        cin>>repl;
        m[cmd]=repl;
    }
    int n=10;
    while(n--)
    {
        for(int i=0; i<pol.size()-1; i++)
        {
            string s="";
            s=s+pol[i]+pol[i+1];
            if(m.find(s)!=m.end())
            {
                char r=m[s];
                pol.insert(pol.begin()+i+1, r);
                i++;
            }
        }
    }
    //cout<<string(pol.begin(), pol.end())<<endl;
    for(int i=0; i<pol.size(); i++)
    {
        char c=pol[i];
        if(occ.find(c)!=occ.end())
        {
            occ[c]++;
        }
        else
        {
            occ[c]=1;
        }
    }
    int maxo=0, mino=9999999;
    for(auto it=occ.begin(); it!=occ.end(); it++)
    {
        if(it->second>maxo)
            maxo=it->second;
        if(it->second<mino)
            mino=it->second;
    }
    cout<<maxo-mino<<endl;
}