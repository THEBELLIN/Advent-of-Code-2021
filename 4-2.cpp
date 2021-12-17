#include <bits/stdc++.h>
using namespace std;

int schede[100][25];
bool schede_rimaste [100];

bool check_win(int scheda);
void mark_num(int num);
int sum_remaining(int scheda);
int count_schede();

int main()
{
    memset(schede_rimaste, 1, 100);
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
        cout<<"processing: "<<num<<endl;
        mark_num(num);
        for(int i=0; i<100; i++)
        {
            w=check_win(i);
            if(w)
            {
                schede_rimaste[i]=0;
            }

        }
        cout<<"count: "<<count_schede()<<endl;
        if(count_schede()==0)
        {
            cout<<num*sum_remaining(9);
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

int count_schede()
{
    int c=0;
    for(int i=0; i<100; i++)
    {
        if(schede_rimaste[i])
            c++;
    }
    return c;
}