#include <bits/stdc++.h>
using namespace std;

pair<int, bool> fishes[10][10];

void spreadlight(int i, int j);

int main()
{
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
        {
            char c;
            cin>>c;
            int n=c-48;
            fishes[i][j].first=n;
            fishes[i][j].second=0;
        }
    for(int p=1; p<10000; p++)
    {
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                fishes[i][j].first++;
        while(1)
        {
            bool f=0;
            for(int i=0; i<10; i++)
                for(int j=0; j<10; j++)
                {
                    if(fishes[i][j].first>9 && fishes[i][j].second==0)
                    {
                        fishes[i][j].second=1;
                        spreadlight(i,j);
                        f=1;
                    }
                }
            if(!f)
                break;
        }
        bool s=1;
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
            {
                if(fishes[i][j].first<10)
                {
                    s=0;
                    break;
                }
            }
        if(s)
        {
            cout<<p<<endl;
            break;
        }
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
            {
                if(fishes[i][j].first>9)
                {
                    fishes[i][j].first=0;
                    fishes[i][j].second=0;
                }
            }
    }
}

void spreadlight(int i, int j)
{
    if(i==0 && j==0) //alto sx
    {
        fishes[0][1].first++;
        fishes[1][1].first++;
        fishes[1][0].first++;
        return;
    }
      if(i==0 && j==9) //alto dx
    {
        fishes[0][8].first++;
        fishes[1][9].first++;
        fishes[1][8].first++;
        return;
    }
      if(i==9 && j==0) //basso sx
    {
        fishes[8][0].first++;
        fishes[8][1].first++;
        fishes[9][1].first++;
        return;
    }
      if(i==9 && j==9) //basso dx
    {
        fishes[9][8].first++;
        fishes[8][8].first++;
        fishes[8][9].first++;
        return;
    }
    if(i==0) //bordo alto
    {
        fishes[0][j-1].first++;
        fishes[0][j+1].first++;
        fishes[1][j-1].first++;
        fishes[1][j].first++;
        fishes[1][j+1].first++;
        return;
    }
     if(j==0) //bordo sx
    {
        fishes[i-1][0].first++;
        fishes[i+1][0].first++;
        fishes[i-1][1].first++;
        fishes[i][1].first++;
        fishes[i+1][1].first++;
        return;
    }
     if(j==9) //bordo dx
       {
        fishes[i-1][9].first++;
        fishes[i+1][9].first++;
        fishes[i-1][8].first++;
        fishes[i][8].first++;
        fishes[i+1][8].first++;
        return;
    }
     if(i==9) //bordo basso
    {
        fishes[9][j-1].first++;
        fishes[9][j+1].first++;
        fishes[8][j-1].first++;
        fishes[8][j].first++;
        fishes[8][j+1].first++;
        return;
    }
    else
    {
        fishes[i-1][j-1].first++;
        fishes[i-1][j].first++;
        fishes[i-1][j+1].first++;
        fishes[i][j-1].first++;
        fishes[i][j+1].first++;
        fishes[i+1][j-1].first++;
        fishes[i+1][j].first++;
        fishes[i+1][j+1].first++;
        return;
    }
}