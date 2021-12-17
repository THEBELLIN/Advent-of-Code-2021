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
        if(x1==x2) //caso verticale
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
        else if(y1==y2)//caso orizzontale
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
        else if(abs(x1-x2)==abs(y1-y2)) //caso diagonale
        {
            if(x1>x2)
            {
                int tmp=x1;
                x1=x2;
                x2=tmp;
                tmp=y1;
                y1=y2;
                y2=tmp;
            }
            //x1 sempre < x2
            if(y2>y1)
            {
                int curr_x=x1, curr_y=y1;
                while(1)
                {
                    field[curr_y][curr_x]++;
                    if(curr_x==x2)
                        break;
                    curr_x++;
                    curr_y++;
                }
            }
            else if(y1>y2)
            {
                    int curr_x=x1, curr_y=y1;
                while(1)
                {
                    field[curr_y][curr_x]++;
                    if(curr_x==x2)
                        break;
                    curr_x++;
                    curr_y--;
                }
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