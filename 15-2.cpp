#include <bits/stdc++.h>
using namespace std;

int cave[500][500];
int risk[500][500];

int main()
{
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            char a;
            cin>>a;
            int aa=a-48;
            for(int k=0; k<5;k++)
            {
                for(int kk=0; kk<5;kk++)
                {
                    cave[100*k+i][100*kk+j]=(aa+k+kk)%9;
                    if(cave[100*k+i][100*kk+j]==0)
                        cave[100*k+i][100*kk+j]=9;
                    risk[100*k+i][100*kk+j]=99999999;
                }
            }

        }
    }
    queue<pair<int, int>> q;
    q.push({0,0});
    risk[0][0]=0;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        if(p.second!=499 && risk[p.first][p.second]+cave[p.first][p.second+1]<risk[p.first][p.second+1])
        {
            risk[p.first][p.second+1]=risk[p.first][p.second]+cave[p.first][p.second+1];
            q.push({p.first,p.second+1});
        }
        if(p.second!=0 && risk[p.first][p.second]+cave[p.first][p.second-1]<risk[p.first][p.second-1])
        {
            risk[p.first][p.second-1]=risk[p.first][p.second]+cave[p.first][p.second-1];
            q.push({p.first,p.second-1});
        }
        if(p.first!=499 && risk[p.first][p.second]+cave[p.first+1][p.second]<risk[p.first+1][p.second])
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
    cout<<risk[499][499];
}