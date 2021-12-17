#include <bits/stdc++.h>
using namespace std;

bool paper[1400][1400]={0};
int maxx, maxy;

void foldV(int x);
void foldH(int y);
void printmat();

int main()
{
    maxx=0;
    maxy=0;
    while(1)
    {
        int x, y;
        cin>>x>>y;
        if(x==-1)
            break;
        if(x>maxx)
            maxx=x;
        if(y>maxy)
            maxy=y;
        paper[y][x]=1;
    }
    //printmat();
    foldV(655);
    //cout<<endl;
    //printmat();
    int c=0;
    for(int i=0; i<=maxy; i++)
    {
        for(int j=0; j<=maxx; j++)
        {
            if(paper[i][j])
                c++;
        }
    }
    cout<<c;
}

void foldV(int x)
{
    for(int i=0; i<=maxy; i++)
    {
        for(int j=x+1; j<=maxx; j++)
        {
            if(paper[i][j])
                paper[i][x-(j-x)]=1;
        }
    }
    maxx=x-1;
}

void foldH(int y)
{
    for(int i=y+1; i<=maxy; i++)
    {
        for(int j=0; j<=maxx; j++)
        {
            if(paper[i][j])
                paper[y-(i-y)][j]=1;
                //cout<<"flipping "<<i<<","<<j<<" to "<<y-(i-y)<<","<<j<<endl;
        }
    }
    maxy=y-1;
}

void printmat()
{
    for(int i=0; i<=maxy; i++)
    {
        for(int j=0; j<=maxx; j++)
        {
           if(paper[i][j])
                cout<<"*";
           else
                cout<<".";
        }
        cout<<endl;
    }
}