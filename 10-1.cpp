#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    int points=0;
    while(1)
    {
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
                    if(c==')')
                        points+=3;
                    if(c==']')
                        points+=57;
                    if(c=='}')
                        points+=1197;
                    if(c=='>')
                        points+=25137;
                    break;
                }
            }
        }
    }
    cout<<points<<endl;
}