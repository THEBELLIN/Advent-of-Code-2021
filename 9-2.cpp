#include <bits/stdc++.h>
using namespace std;

pair<bool,bool> numeri[110][110]; //numero, counted
int countarea=0;

void dfs(int col, int row);

int main()
{
    int maxarea1=-1, maxarea2=-2, maxarea3=-3;
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
        {
            char ch;
            cin>>ch;
            int n= ch-48;
            if(n==9)
                numeri[i][j]={1,1};
            else
                numeri[i][j]={0,0};
        }
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(numeri[i][j].second==0)
            {
                countarea=0;
                dfs(i,j);
                //cout<<"countarea: "<<countarea<<endl;
                if(countarea>maxarea1 && maxarea1<=maxarea2 && maxarea1<=maxarea3)
                    maxarea1=countarea;
                else if(countarea>maxarea2 && maxarea2<=maxarea1 && maxarea2<=maxarea3)
                    maxarea2=countarea;
                else if(countarea>maxarea3 && maxarea3<=maxarea2 && maxarea3<=maxarea1)
                    maxarea3=countarea;
            }
        }
    }
    //cout<<"max1: "<<maxarea1<<", max2: "<<maxarea2<<", max3: "<<maxarea3<<endl;
    long long prod=maxarea1*maxarea2*maxarea3;
    cout<<prod<<endl;
}

void dfs(int row, int col)
{
    numeri[row][col].second=1;
    countarea++;
    //cout<<"called dfs on: "<<row<<","<<col<<", counter: "<<countarea<<endl;
    if(row==0 && col==0) //angolo alto sx
    {
        if(numeri[row][col+1].second==0)
            dfs(row, col+1);
        if(numeri[row+1][col].second==0)
            dfs(row+1, col);
        return;
    }
     if(row==0 && col==99) //angolo alto dx
    {
        if(numeri[row][col-1].second==0)
            dfs(row, col-1);
        if(numeri[row+1][col].second==0)
            dfs(row+1, col);
        return;
    }
     if(row==99 && col==0) //angolo basso sx
    {
        if(numeri[row][col+1].second==0)
            dfs(row, col+1);
        if(numeri[row-1][col].second==0)
            dfs(row-1, col);
        return;
    }
     if(row==99 && col==99) //angolo basso dx
    {
        if(numeri[row][col-1].second==0)
            dfs(row, col-1);
        if(numeri[row-1][col].second==0)
            dfs(row-1, col);
        return;
    }
    if(row==0) //riga alta
    {
        if(numeri[row][col-1].second==0)
            dfs(row, col-1);
        if(numeri[row][col+1].second==0)
            dfs(row, col+1);
        if(numeri[row+1][col].second==0)
            dfs(row+1, col);
        return;
    }
    if(col==0) //riga sx
    {
        if(numeri[row-1][col].second==0)
            dfs(row-1, col);
        if(numeri[row+1][col].second==0)
            dfs(row+1, col);
        if(numeri[row][col+1].second==0)
            dfs(row, col+1);
        return;
    }
    if(col==99) //riga dx
    {
        if(numeri[row-1][col].second==0)
            dfs(row-1, col);
        if(numeri[row+1][col].second==0)
            dfs(row+1, col);
        if(numeri[row][col-1].second==0)
            dfs(row, col-1);
        return;
    }
    if(row==99) //riga bassa
    {
        if(numeri[row][col-1].second==0)
            dfs(row, col-1);
        if(numeri[row][col+1].second==0)
            dfs(row, col+1);
        if(numeri[row-1][col].second==0)
            dfs(row-1, col);
        return;
    }
    else //numeri centrali
    {
        if(numeri[row+1][col].second==0)
            dfs(row+1, col);
        if(numeri[row-1][col].second==0)
            dfs(row-1, col);
        if(numeri[row][col+1].second==0)
            dfs(row, col+1);
        if(numeri[row][col-1].second==0)
            dfs(row, col-1);
        return;
    }
}