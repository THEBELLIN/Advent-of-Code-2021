#include <bits/stdc++.h>
using namespace std;

int field[1000][1000] = {0};

int main()
{
    int x1, x2, y1, y2;
    while(1)
    {
        cin>>x1;
        if(x1==-1)
            break;
        cin>>y1>>x2>>y2;
        if(x1==x2)
        {
            if(y1>y2)
            {
                int tmp=y1;
                y1=y2;
                y2=tmp;
            }
            for(int i=y1; i<=y2; i++)
            {
                field[i][x1]++;
            }
        }
        else if(y1==y2)//y1==y2
        {
             if(x1>x2)
            {
                int tmp=x1;
                x1=x2;
                x2=tmp;
            }
            for(int i=x1; i<=x2; i++)
            {
                field[y1][i]++;
            }
        }
    }
    int c=0;
    for(int i=0; i<1000; i++)
    {
        for(int j=0; j<1000; j++)
        {
            if(field[i][j]>1)
                c++;

        }
    }
    cout<<c<<endl;
}