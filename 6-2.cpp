#include <bits/stdc++.h>
using namespace std;

map<int, long long> fishes;
map<int, long long> newfishes;

int main()
{
    fishes[0]=0;
    fishes[1]=0;
    fishes[2]=0;
    fishes[3]=0;
    fishes[4]=0;
    fishes[5]=0;
    fishes[6]=0;
    fishes[7]=0;
    fishes[8]=0;
    while(1)
    {
        int fish;
        cin>>fish;
        if(fish==-1)
            break;
        fishes[fish]++;
    }
    int time=256;
    while(time--)
    {
       newfishes[8]=fishes[0];
       newfishes[7]=fishes[8];
       newfishes[6]=fishes[7]+fishes[0];
       newfishes[5]=fishes[6];
       newfishes[4]=fishes[5];
       newfishes[3]=fishes[4];
       newfishes[2]=fishes[3];
       newfishes[1]=fishes[2];
       newfishes[0]=fishes[1];
       fishes=newfishes;
    }
    long long c=0;
    for(int i=0; i<9; i++)
    {
        c+=fishes[i];
    }
    cout<<c<<endl;
}