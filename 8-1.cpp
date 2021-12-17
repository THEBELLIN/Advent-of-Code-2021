#include <bits/stdc++.h>
using namespace std;


int main()
{
    int c=0;
    while(1)
    {
        string line, s;
        getline(cin, line);
        if(line=="0")
            break;
        stringstream input(line);
        while(input>>s)
        {
            if(s=="|")
                break;
        }

        for(int i=0; i<4;i++)
        {
            input>>s;
            if(s.length()== 2 || s.length()== 3 || s.length()== 4 || s.length()== 7)
                c++;
        }
    }
    cout<<c;
}