#include <bits/stdc++.h>
using namespace std;

int numeri[110][110];
vector<pair<int,int>> lowpoints;

int main()
{
    int c=0;
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
        {
            char ch;
            cin>>ch;
            int n= ch-48;
            numeri[i][j]=n;
        }
    for(int i=0; i<100; i++) //check righe
    {
        if(numeri[i][0]<numeri[i][1])
            lowpoints.push_back({i,0});
        for(int j=1; j<99; j++)
        {
            if(numeri[i][j]<numeri[i][j+1] && numeri[i][j]<numeri[i][j-1])
                lowpoints.push_back({i,j});
        }
        if(numeri[i][99]<numeri[i][98])
            lowpoints.push_back({i,99});
    }

     for(int i=0; i<100; i++) //check colonne
     {
        if(numeri[0][i]<numeri[1][i])
            for(int k=0; k<lowpoints.size(); k++)
            {
                if(lowpoints[k].first==0 && lowpoints[k].second==i)
                    c+=numeri[0][i]+1;
            }
        for(int j=1; j<99; j++)
        {
            if(numeri[j][i]<numeri[j+1][i] && numeri[j][i]<numeri[j-1][i])
            {
               for(int k=0; k<lowpoints.size(); k++)
                {
                    if(lowpoints[k].first==j && lowpoints[k].second==i)
                        c+=numeri[j][i]+1;
                }
            }
        }
        if(numeri[99][i]<numeri[98][i])
            for(int k=0; k<lowpoints.size(); k++)
            {
                if(lowpoints[k].first==99 && lowpoints[k].second==i)
                    c+=numeri[99][i]+1;
            }
    }
    cout<<c;
}
