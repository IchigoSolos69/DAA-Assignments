#include <iostream>
#include <climits>
#define INF INT_MAX
using namespace std;

void dijkstra(int graph[10][10], int V, int src)
{
    int dist[10];
    bool visited[10];
    for(int i=0; i<V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;

    for(int count=0; count< V-1; count++)
    {
        int u=-1;
        int min=INF;

        for(int i=0; i<V; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = true;

        for(int v=0; v<V; v++)
        {
            if(!visited[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    cout<<"\nVertex\t Distance from source\t\n";

    for(int i=0; i<V; i++)
    {
        cout<<i<<"\t";
        if(dist[i] == INF)
            cout<<"No path.";
        else
            cout<<dist[i]<<"\t\n";
    }
}

int main()
{
    int V, src, graph[10][10];

    cout<<"Enter number of vertices (1-10)=";
    cin>>V;

    if(V>10 || V<1)
    {
        cout<<"\nInvalid choice enter between 1-10.";
        return 1;
    }

    cout<<"\nEnter adjacency matrix:\n";
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cin>>graph[i][j];
        }
    }

    cout << "\nEnter source (0 - " << V-1 << ")=";
    cin>>src;

    if(src>=V || src<0)
    {
        cout<<"\nInvalid choice enter between 1-10.";
        return 1;
    }

    dijkstra(graph, V, src);

    return 0;
}
