#include <bits/stdc++.h>
using namespace std;

int schede[100][25];

bool check_win(int scheda);
void mark_num(int num);
int sum_remaining(int scheda);

int main()
{
    int scheda=0;
    while(scheda<100) //input schede
    {
        for(int i=0; i<25; i++)
        {
            cin>>schede[scheda][i];
        }
        scheda++;
    }
    bool w=0;
    while(1)
    {
        int num, sum;
        cin>>num;
        mark_num(num);
        for(int i=0; i<100; i++)
        {
            w=check_win(i);
            if(w)
            {
                sum=sum_remaining(i);
                break;
            }

        }
        if(w)
        {
            cout<<sum*num<<endl;
            break;
        }
    }

}

bool check_win(int scheda)
{
    bool r=1;
    for(int i=0; i<5; i++) //check righe
    {
        r=1;
        for(int j=5*i; j<5*i+5; j++)
        {
            if(schede[scheda][j]!=-1)
            {
                r=0;
                break;
            }
        }
        if(r)
            break;
    }
    if(r)
        return 1;
    for(int i=0; i<5; i++) //check colonne
    {
        r=1;
        for(int j=i; j<25; j=j+5)
        {
            if(schede[scheda][j]!=-1)
            {
                r=0;
                break;
            }
        }
        if(r)
            break;
    }
    if(r)
        return 1;
    return 0;
}

void mark_num (int num)
{
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<25; j++)
        {
            if(schede[i][j]==num)
                schede[i][j]=-1;
        }
    }
}

int sum_remaining(int scheda)
{
    int sum=0;
    for(int i=0; i<25; i++)
    {
        if(schede[scheda][i]!=-1)
            sum+=schede[scheda][i];
    }
    return sum;
}