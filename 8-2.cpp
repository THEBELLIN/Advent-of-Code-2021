#include <bits/stdc++.h>
using namespace std;

map<int, int> occorrenze;
map <char, int> conversione;
map <int, char> conversione_inv;
map<int,string> numeri;
map <char, char> fili;

int ston(string s);

int main()
{
    int c=0;
    conversione['a']=0;
    conversione['b']=1;
    conversione['c']=2;
    conversione['d']=3;
    conversione['e']=4;
    conversione['f']=5;
    conversione['g']=6;
    conversione_inv[0]='a';
    conversione_inv[1]='b';
    conversione_inv[2]='c';
    conversione_inv[3]='d';
    conversione_inv[4]='e';
    conversione_inv[5]='f';
    conversione_inv[6]='g';
    while(1)
    {
        occorrenze[0]=0; //a
        occorrenze[1]=0; //b
        occorrenze[2]=0; //c
        occorrenze[3]=0; //d
        occorrenze[4]=0; //e
        occorrenze[5]=0; //f
        occorrenze[6]=0; //g
        string line, s;
        getline(cin, line);
        if(line=="0")
            break;
        stringstream input(line);
        while(input>>s)
        {
            if(s=="|")
                break;
            for(int i=0; i<s.length(); i++) //conta occorrenze
            {
                char k = s[i];
                int index=conversione[k];
                occorrenze[index]++;
            }
            if(s.length()==2) //1
                numeri[1]=s;
            if(s.length()==3) //7
                numeri[7]=s;
            if(s.length()==4) //4
                numeri[4]=s;
        }

        //b, e, f
        for(int i=0; i<7;i++)
        {
            if(occorrenze[i]==6) //b
            {
                char ch=conversione_inv[i];
                fili['b']=ch;
            }
            if(occorrenze[i]==4) //e
            {
                char ch=conversione_inv[i];
                fili['e']=ch;
            }
            if(occorrenze[i]==9) //f
            {
                char ch=conversione_inv[i];
                fili['f']=ch;
            }
        }

        //c
        string uno=numeri[1];
        char uno_u =uno[0], uno_d=uno[1];
        if(uno_u!=fili['f'])
            fili['c']=uno_u;
        if(uno_d!=fili['f'])
            fili['c']=uno_d;

        //d
        string quattro=numeri[4];
        char quattro_u=quattro[0], quattro_d=quattro[1], quattro_t=quattro[2], quattro_q=quattro[3];
        if(quattro_u!=fili['b'] && quattro_u!=fili['c'] && quattro_u!=fili['f'])
            fili['d']=quattro_u;
        if(quattro_d!=fili['b'] && quattro_d!=fili['c'] && quattro_d!=fili['f'])
            fili['d']=quattro_d;
        if(quattro_t!=fili['b'] && quattro_t!=fili['c'] && quattro_t!=fili['f'])
            fili['d']=quattro_t;
        if(quattro_q!=fili['b'] && quattro_q!=fili['c'] && quattro_q!=fili['f'])
            fili['d']=quattro_q;

        //a
        string sette=numeri[7];
        char sette_u=sette[0], sette_d=sette[1], sette_t=sette[2];
        if(sette_u!=fili['c'] && sette_u!=fili['f'])
            fili['a']=sette_u;
        if(sette_d!=fili['c'] && sette_d!=fili['f'])
            fili['a']=sette_d;
        if(sette_t!=fili['c'] && sette_t!=fili['f'])
            fili['a']=sette_t;

        //g
        for(char cc='a'; cc<'h'; cc++)
        {
            if(fili['a']==cc || fili['b']==cc || fili['c']==cc || fili['d']==cc || fili['e']==cc || fili['f']==cc)
                continue;
            else
                fili['g']=cc;
        }

        int num=0;
        for(int i=0; i<4;i++)
        {
            input>>s;
            int n=ston(s);
            c+=n*pow(10, 3-i);
        }
    }
    cout<<c;
}

int ston(string s)
{
    bool a=0, b=0, c=0, d=0, e=0, f=0, g=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]==fili['a'])
            a=1;
        if(s[i]==fili['b'])
            b=1;
        if(s[i]==fili['c'])
            c=1;
        if(s[i]==fili['d'])
            d=1;
        if(s[i]==fili['e'])
            e=1;
        if(s[i]==fili['f'])
            f=1;
        if(s[i]==fili['g'])
            g=1;
    }
    if(a&&b&&c&&!d&&e&&f&&g)
        return 0;
    if(!a&&!b&&c&&!d&&!e&&f&&!g)
        return 1;
    if(a&&!b&&c&&d&&e&&!f&&g)
        return 2;
    if(a&&!b&&c&&d&&!e&&f&&g)
        return 3;
    if(!a&&b&&c&&d&&!e&&f&&!g)
        return 4;
    if(a&&b&&!c&&d&&!e&&f&&g)
        return 5;
    if(a&&b&&!c&&d&&e&&f&&g)
        return 6;
    if(a&&!b&&c&&!d&&!e&&f&&!g)
        return 7;
    if(a&&b&&c&&d&&e&&f&&g)
        return 8;
    if(a&&b&&c&&d&&!e&&f&&g)
        return 9;
}