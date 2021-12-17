#include <bits/stdc++.h>
using namespace std;

int cave[100][100];
int risk[100][100];

int main()
{
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            char a;
            cin>>a;
            int aa=a-48;
            cave[i][j]=aa;
            risk[i][j]=999999;
        }
    }
    queue<pair<int, int>> q;
    q.push({0,0});
    risk[0][0]=0;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        if(p.second!=99 && risk[p.first][p.second]+cave[p.first][p.second+1]<risk[p.first][p.second+1])
        {
            risk[p.first][p.second+1]=risk[p.first][p.second]+cave[p.first][p.second+1];
            q.push({p.first,p.second+1});
        }
        if(p.second!=0 && risk[p.first][p.second]+cave[p.first][p.second-1]<risk[p.first][p.second-1])
        {
            risk[p.first][p.second-1]=risk[p.first][p.second]+cave[p.first][p.second-1];
            q.push({p.first,p.second-1});
        }
        if(p.first!=99 && risk[p.first][p.second]+cave[p.first+1][p.second]<risk[p.first+1][p.second])
        {
            risk[p.first+1][p.second]=risk[p.first][p.second]+cave[p.first+1][p.second];
            q.push({p.first+1,p.second});
        }
        if(p.first!=0 && risk[p.first][p.second]+cave[p.first-1][p.second]<risk[p.first-1][p.second])
        {
            risk[p.first-1][p.second]=risk[p.first][p.second]+cave[p.first-1][p.second];
            q.push({p.first-1,p.second});
        }
        q.pop();
    }
    cout<<risk[99][99];
}