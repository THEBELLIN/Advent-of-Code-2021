#include <bits/stdc++.h>
using namespace std;

int minx=124;
int maxx=174;
int miny=-123;
int maxy=-86;
int xvel;
int yvel;
int curryvel;
int currxvel;
int maxh=0;
int currmaxh;
pair<int,int> position;

void updateposition();
void checkposition();

int main()
{

    for(int x=0; x<1000; x++)
    {
        for(int y=0; y<125;y++)
        {
            position={0,0};
            currxvel=x;
            xvel=x;
            curryvel=y;
            yvel=y;
            currmaxh=-99999;
            for(int k=0; k<400; k++)
            {
                updateposition();
                checkposition();
            }
        }
    }
    cout<<"max height: "<<maxh<<endl;
}

void updateposition()
{
    position.first+=xvel;
    position.second+=yvel;
    if(xvel>0)
        xvel--;
    if(xvel<0)
        xvel++;
    yvel--;
    if(position.second>currmaxh)
        currmaxh=position.second;
}

void checkposition()
{
    if(position.first>=minx && position.first<=maxx && position.second>=miny && position.second<=maxy)
    {
        //cout<<"reached target with initial velocity of: ("<<currxvel<<","<<curryvel<<")"<<endl;
        if(currmaxh>maxh)
        {
            maxh=currmaxh;
            cout<<"starting vleocity: ("<<currxvel<<","<<curryvel<<")"<<endl;
        }

    }

}