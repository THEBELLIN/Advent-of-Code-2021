#include <bits/stdc++.h>
using namespace std;

string hexs;
string bins;
int index=0;
int totall;

string hextobin(string s);
long long binstringtoint(string s);
long long parsestring(string s);
long long updatevalue(long long v, long long tempv, int type);

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
    //cout<<bins<<endl;
    totall=bins.length();
    cout<<parsestring(bins)<<endl;
}

long long parsestring(string s)
{
    //cout<<"parsing, current sum: "<<sumversions<<endl;
    int ll=index;
    //sumversions+=binstringtoint(s.substr(index,3));
    index+=3;
    int type=binstringtoint(s.substr(index,3));
    index+=3;
    if(type==4) //literal value
    {
        //cout<<"literal value: "<<endl;
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
        long long v=binstringtoint(value);
        cout<<"literal value: "<<v<<endl;
        return v;
    }
    else //operand
    {
        //cout<<"operand: "<<endl;
        if(s[index]=='0') //15 bits total length
        {
            //cout<<"type 0, reading next 15 bits"<<endl;
            index++;
            int l=binstringtoint(s.substr(index,15));
            index+=15;
            //cout<<"length to read: "<<l<<", index to reach: "<<index+l<<endl;
            int currindex=index;
            if(type==0 || type==1 || type==2 || type==3)
            {
                long long v=0;
                if(type==2)
                    v=9999999999;
                if(type==1)
                    v=1;
                while(index<currindex+l)
                {
                    long long tempv=parsestring(s);
                    if(type==0 || type==1 || type==2 || type==3)
                        v=updatevalue(v,tempv, type);
                }
                //cout<<"finished operand type 0"<<endl;
                return v;
            }
            else
            {
                long long v1=parsestring(s), v2=parsestring(s);
                if(type==5)
                {
                    if(v1>v2)
                        return 1;
                    else
                        return 0;
                }
                else if(type==6)
                {
                    if(v1<v2)
                        return 1;
                    else
                        return 0;
                }
                else if(type==7)
                {
                    if(v1==v2)
                        return 1;
                    else
                        return 0;
                }
            }

        }
        else //11 bits of number of packets
        {
            long long v=0;
            if(type==2)
                v=9999999999;
            if(type==1)
                v=1;
            index++;
            //cout<<"operand type 1, reading next 11 bits"<<endl;
            int n=binstringtoint(s.substr(index,11));
            index+=11;
            //cout<<"#pckts: "<<n<<", current index: "<<index<<endl;
            if(type==0 || type==1 || type==2 || type==3)
            {
                for(int j=0; j<n; j++)
                {
                    long long tempv=parsestring(s);
                    v=updatevalue(v, tempv, type);
                }
                cout<<"operand value: "<<v<<endl;
                return v;
            }
            else
            {
                long long v1=parsestring(s), v2=parsestring(s);
                if(type==5)
                {
                    if(v1>v2)
                        return 1;
                    else
                        return 0;
                }
                else if(type==6)
                {
                    if(v1<v2)
                        return 1;
                    else
                        return 0;
                }
                else if(type==7)
                {
                    if(v1==v2)
                        return 1;
                    else
                        return 0;
                }
            }
            //cout<<"finished operand type 1"<<endl;
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

long long binstringtoint(string s)
{
    int l=s.length();
    long long ans=0;
    for(int i=0; i<l;i++)
    {
        if(s[i]=='1')
            ans+=pow(2,l-1-i);
    }
    return ans;
}

long long updatevalue(long long v, long long tempv, int type)
{
    long long returnv;
    switch(type)
    {
        case 0: //sum
        {
            returnv=v+tempv;
            break;
        }
        case 1: //product
        {
            returnv=v*tempv;
            break;
        }
        case 2: //minimum
        {
            returnv=min(v,tempv);
            break;
        }
        case 3: //maximum
        {
            returnv=max(v,tempv);
            break;
        }
        case 5: //greater than
        {
            if(v>tempv)
                returnv=1;
            else
                returnv=0;
            break;
        }
        case 6: //less than
        {
            if(v<tempv)
                returnv=1;
            else
                returnv=0;
            break;
        }
        case 7: //equal to
        {
            if(v==tempv)
                returnv=1;
            else
                returnv=0;
            break;
        }
        return returnv;
    }
}