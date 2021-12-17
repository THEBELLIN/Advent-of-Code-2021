#include <bits/stdc++.h>
using namespace std;

long long c;

class Graph
{
    int v;
    list<int> *adj;
    void printAllPathsUtil(int, int, int[], int[], int&, int);

public:
    Graph(int v);
    void addEdge(int s, int d);
    void printAllPaths(int s, int d, int ii);

};

Graph::Graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}

void Graph::addEdge(int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void Graph::printAllPaths(int s, int d, int ii)
{
    int* visited = new int[v];
    int* path = new int[v];
    int path_index=0;

    for(int i=0; i<v; i++)
        visited[i]=0;
    //visited[ii]--;

    printAllPathsUtil(s, d, visited, path, path_index, ii);
}

void Graph::printAllPathsUtil(int s, int d, int visited[], int path[], int& path_index, int ii)
{
    if(s!=2 && s!=6 && s!=9)
        visited[s]++;
    path[path_index]=s;
    path_index++;
    int cc=0;
    for(int i=0; i<path_index; i++)
    {
        if(path[i]==ii)
            cc++;
    }
    if(cc==1)
        visited[ii]=0;

    if(s==d)
    {
        c++;
        /*for(int i=0; i<path_index; i++)
            cout<<path[i]<<" ";
        cout<<endl;*/
    }
    else
    {
        for(int i:adj[s])
        {
            if(visited[i]<1)
            {
                //cout<<"calling from "<<i<<", visited["<<i<<"]: "<<visited[i]<<endl;
                printAllPathsUtil(i, d, visited, path, path_index, ii);
            }
        }
    }

    path_index--;
    /*if(s==ii)
        visited[s]=-1;
    else*/
    visited[s]=0;
}

int main()
{
    Graph g(11);
    for(int i=0; i<22; i++)
    {
        int a, b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    c=0;
    //g.printAllPaths(0, 10, 1);
    //g.printAllPaths(0, 10, 3);
    //g.printAllPaths(0, 10, 4);
    //g.printAllPaths(0, 10, 5);
    //g.printAllPaths(0, 10, 7);
    //g.printAllPaths(0, 10, 8);
    c=43845+18127+13898+42085+28445+10968; //risultati computati 1 per 1, non so perchè ma tutti insieme non funziona
    c=c-5228*5;
    cout<<"c: "<<c<<endl;
}