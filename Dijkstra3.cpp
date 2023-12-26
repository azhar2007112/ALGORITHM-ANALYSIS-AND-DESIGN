
#include<bits/stdc++.h>
using namespace std;
int cost[5];
const int inf = 100000;
int visited[5] = {0};
void addEdge(int adj[][5], int x,int y, int cost)
{
    adj[x][y] = cost;
    adj[y][x] = cost;
}

void dijkstra(int adj[][5], int start)
{
    cost[start] = 0;
    for(int i=0; i<5; i++){
        if(adj[start][i] != inf){
            if(cost[i] > cost [start] + adj[start][i]){
                cost[i] = cost [start] + adj[start][i];
            }
        }
    }
    visited[start] = 1;


}

int main()
{
    const int v = 5;
    int adj[v][v];

    for(int i=0; i<v; i++)
    {
        cost[i] = inf;
        for(int j=0; j<v; j++)
        {
            adj[i][j]=inf;
        }
        cout<<endl;
    }

    addEdge(adj,0,1,10);
    addEdge(adj,0,2,20);
    addEdge(adj,1,2,12);
    addEdge(adj,2,4,16);

//    for(int i=0; i<v; i++)
//    {
//        for(int j=0; j<v; j++)
//        {
//            cout<<adj[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    dijkstra(adj, 0);
    for(int i = 0; i<5; i++){
        cout<<i<<" "<<cost[i]<<endl;
    }
}
