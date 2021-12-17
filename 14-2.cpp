#include <bits/stdc++.h>
using namespace std;

map<string, char> m;
map<string, long long> occ;
map<string, long long> occ2;
map<char, long long> numchar;

int main()
{
    string p="";
    while(1)
    {
        char c;
        cin>>c;
        if(c=='-')
            break;
        p+=c;
        if(numchar.find(c)!=numchar.end())
            numchar[c]++;
        else
            numchar[c]=1;
    }

    for(int i=0; i<p.length()-1; i++)
    {
        string ss="";
        ss=ss+p[i]+p[i+1];
        if(occ.find(ss)!=occ.end())
            occ[ss]++;
        else
            occ[ss]=1;
    }
    occ2=occ;
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
    int n=40;
   /* for(auto i:occ)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }*/
    while(n--)
    {
        //cout<<n<<endl;
        for(auto i:occ)
        {
            string s=i.first;
            long long num=i.second;
            char interm=m[s];
            string sc="", cs="";
            sc=sc+s[0]+interm;
            cs=cs+interm+s[1];
            //cout<<num<<" "<<s<<" : "<<sc<<" + "<<cs<<endl;
            occ2[s]=occ2[s]-num;
            //cout<<"old: "<<occ2[sc]<<", "<<occ2[cs]<<" ";
            occ2[sc]=occ2[sc]+num;
            occ2[cs]=occ2[cs]+num;
            //cout<<"new: "<<occ2[sc]<<", "<<occ2[cs]<<" "<<endl;;
            if(numchar.find(interm)!=numchar.end())
                numchar[interm]+=num;
            else
                numchar[interm]=num;
        }
        occ=occ2;
        /*cout<<"list:"<<endl;
        for(auto i:occ)
        {
            cout<<i.first<<" : "<<i.second<<endl;
        }*/
    }
    long long maxo=0, mino=999999999999999;
    for(auto i:numchar)
    {
        //cout<<i.first<<" : "<<i.second<<endl;
        if(i.second>maxo)
            maxo=i.second;
        if(i.second<mino)
            mino=i.second;
    }
    cout<<maxo-mino<<endl;
}