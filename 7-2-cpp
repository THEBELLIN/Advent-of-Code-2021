#include <bits/stdc++.h>
using namespace std;

vector<int> crabs;

int main()
{
    int num;
    while(1)
    {
        cin>>num;
        if(num==-1)
            break;
        crabs.push_back(num);
    }
    int minsum=9999999999;
    for(int i=0; i<crabs.size();i++)
    {
        int cumsum=0;
        for(int j=0; j<crabs.size(); j++)
        {
            int diff=abs(crabs[j]-i);
            cumsum+=(diff*(diff+1)/2);
        }
        if(cumsum<minsum)
            minsum=cumsum;
    }
    cout<<minsum<<endl;
}