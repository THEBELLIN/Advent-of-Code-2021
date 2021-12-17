#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    long long points=0;
    vector<long long> pointvec;
    while(1)
    {
        points=0;
        getline(cin, line);
        string zero="0";
        if(line.compare(zero)==0)
            break;
        stack<char> q;
        for(int i=0; i<line.length(); i++)
        {
            char c=line[i];
            if(c=='(' || c=='[' || c=='{' || c=='<')
            {
                //cout<<"pushing: "<<c<<endl;
                q.push(c);
            }
            else
            {
                char cc=q.top();
                //cout<<"cc: "<<cc<<endl;
                if((cc=='(' && c==')') || (cc=='[' && c==']') || (cc=='{' && c=='}') || (cc=='<' && c=='>'))
                    {
                         q.pop();
                         //cout<<"popped: "<<cc<<endl;
                    }
                else
                {
                    while(!q.empty())
                        q.pop();
                    break;
                }
            }
        }
        while(!q.empty())
        {
            char cc=q.top();
            points*=5;
            if(cc=='(')
                points+=1;
            if(cc=='[')
                points+=2;
            if(cc=='{')
                points+=3;
            if(cc=='<')
                points+=4;
            q.pop();
        }
        if(points>0)
        {
            pointvec.push_back(points);
            cout<<"pushing back: "<<points<<endl;
        }
    }
    sort(pointvec.begin(), pointvec.end());
    int middle=pointvec.size()/2;
    cout<<pointvec[middle]<<endl;
}