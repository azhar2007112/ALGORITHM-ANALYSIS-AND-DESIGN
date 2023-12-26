#include<bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

void printSolution(int dist[][V]);

bool azhar(int graph[][V])
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0)
            return true;
    return false;
}

int main()
{
    int graph[V][V] = { {0   , 1   , INF , INF},
                        {INF , 0   , -1  , INF},
                        {INF , INF , 0   ,  -1},
                        {-1  , INF , INF ,   0}};

    if (azhar(graph))
       cout << "Yes, the graph contains a negative weight cycle.";
    else
       cout << "No, the graph does not contain a negative weight cycle.";

    return 0;
}
