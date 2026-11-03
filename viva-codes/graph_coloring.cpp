#include <iostream>
using namespace std;
#define MAX 10

int graph[MAX][MAX];
int color[MAX];
int v,m;

bool isSafe(int Vertex, int c)
{
    for(int i=0; i<v; i++)
    {
        if(graph[Vertex][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoring(int Vertex)
{
    if(Vertex == v)
        return true;

    for(int c=1; c<=m; c++)
    {
        if(isSafe(Vertex, c))
        {
            color[Vertex] = c;

            if(graphColoring(Vertex+1))
                return true;

            color[Vertex] = 0;
        }
    }
    return false;
}

int main()
{
    cout<<"Enter number of vertices=";
    cin>>v;

    if(v>10 || v<1)
    {
        cout<<"invalid vertex\n";
        return 1;
    }

    cout<<"\nEnter adjacency matrix(1s & 0s):\n";
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cin>>graph[i][j];
        }
    }
    for(m=1; m<=v; m++)
    {
        for(int i=0; i<v; i++)
            color[i] = 0;

        if(graphColoring(0))
        break;
    }

    if(m>v)
    {
        cout<<"\n colouring not possible";
    }
    else
    {
        cout<<"The minimum number of colors="<<m<<endl;
        for(int i=0; i<v; i++)
        {
            cout<<"Vertex "<<i+1<<" color = "<<color[i]<<endl;
        }
    }
    return 0;
}
