#include <bits/stdc++.h>
using namespace std;

string hexs;
string bins;
int sumversions=0;
int index=0;
int totall;

string hextobin(string s);
int binstringtoint(string s);
void parsestring(string s);

int main()
{
    hexs="";
    bins="";
    while(1)
    {
        char c;
        cin>>c;
        if(c=='-')
            break;
        hexs=hexs+c;
    }
    bins=hextobin(hexs);
    cout<<bins<<endl;
    totall=bins.length();
    parsestring(bins);
    cout<<sumversions;
}

void parsestring(string s)
{
    cout<<"parsing, current sum: "<<sumversions<<endl;
    int ll=index;
    sumversions+=binstringtoint(s.substr(index,3));
    index+=3;
    int type=binstringtoint(s.substr(index,3));
    bool op=0;
    if(type!=4)
        op=1;
    index+=3;
    if(!op) //literal value
    {
        cout<<"literal value: "<<endl;
        bool last=false;
        string value="";
        while(1)
        {
            if(s[index]=='0')
                last=1;
            value.append(s.substr(index+1, 4));
            index+=5;
            if(last)
                break;
        }
        cout<<"value: "<<value<<endl;
    }
    else //operand
    {
        cout<<"operand: "<<endl;
        if(s[index]=='0') //15 bits total length
        {
            cout<<"type 0, reading next 15 bits"<<endl;
            index++;
            int l=binstringtoint(s.substr(index,15));
            index+=15;
            cout<<"length to read: "<<l<<", index to reach: "<<index+l<<endl;
            int currindex=index;
            while(index<currindex+l)
            {
                parsestring(s);
            }
            cout<<"finished operand type 0"<<endl;
            return;
        }
        else //11 bits of number of packets
        {
            index++;
            cout<<"operand type 1, reading next 11 bits"<<endl;
            int n=binstringtoint(s.substr(index,11));
            index+=11;
            cout<<"#pckts: "<<n<<", current index: "<<index<<endl;
            for(int j=0; j<n; j++)
            {
                parsestring(s);
            }
            cout<<"finished operand type 1"<<endl;
            return;
        }
    }
}

string hextobin(string s)
{
	string sReturn = "";
    for (int i = 0; i < s.length (); ++i)
    {
        switch (s[i])
        {
            case '0': sReturn.append ("0000"); break;
            case '1': sReturn.append ("0001"); break;
            case '2': sReturn.append ("0010"); break;
            case '3': sReturn.append ("0011"); break;
            case '4': sReturn.append ("0100"); break;
            case '5': sReturn.append ("0101"); break;
            case '6': sReturn.append ("0110"); break;
            case '7': sReturn.append ("0111"); break;
            case '8': sReturn.append ("1000"); break;
            case '9': sReturn.append ("1001"); break;
            case 'A': sReturn.append ("1010"); break;
            case 'B': sReturn.append ("1011"); break;
            case 'C': sReturn.append ("1100"); break;
            case 'D': sReturn.append ("1101"); break;
			case 'E': sReturn.append ("1110"); break;
			case 'F': sReturn.append ("1111"); break;
		}
	}
	return sReturn;
}

int binstringtoint(string s)
{
    int l=s.length();
    int ans=0;
    for(int i=0; i<l;i++)
    {
        if(s[i]=='1')
            ans+=pow(2,l-1-i);
    }
    return ans;
}