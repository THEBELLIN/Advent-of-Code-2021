#include <bits/stdc++.h>
using namespace std;

vector<int> fishes;

int main()
{
    while(1)
    {
        int fish;
        cin>>fish;
        if(fish==-1)
            break;
        fishes.push_back(fish);
    }
    int time=256;
    while(time--)
    {
        int size=fishes.size();
        for(int i=0; i<size; i++)
        {
            if(fishes[i]==0)
            {
                fishes[i]=6;
                fishes.push_back(8);
            }
            else
            {
                fishes[i]--;
            }
        }
    }
    cout<<fishes.size()<<endl;
}