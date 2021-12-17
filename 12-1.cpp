#include <bits/stdc++.h>
using namespace std;

int c;

class Graph
{
    int v;
    list<int> *adj;
    void printAllPathsUtil(int s, int d, bool[], int[], int&);

public:
    Graph(int v);
    void addEdge(int s, int d);
    void printAllPaths(int s, int d);

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

void Graph::printAllPaths(int s, int d)
{
    bool* visited = new bool[v];
    int* path = new int[v];
    int path_index=0;

    for(int i=0; i<v; i++)
        visited[i]=false;

    printAllPathsUtil(s, d, visited, path, path_index);
}

void Graph::printAllPathsUtil(int s, int d, bool visited[], int path[], int& path_index)
{
    if(s!=2 && s!=6 && s!=9)
        visited[s]=1;
    path[path_index]=s;
    path_index++;

    if(s==d)
    {
        c++;
        //for(int i=0; i<path_index; i++)
            //cout<<path[i]<<" ";
        //cout<<endl;
    }
    else
    {
        for(int i:adj[s])
        {
            if(!visited[i])
                printAllPathsUtil(i, d, visited, path, path_index);
        }
    }

    path_index--;
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
    g.printAllPaths(0, 10);
    cout<<"c: "<<c<<endl;
}