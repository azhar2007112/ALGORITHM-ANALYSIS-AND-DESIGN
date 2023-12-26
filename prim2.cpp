#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> p;

int spanningTree(int V, int E, vector<pair<int, pair<int, int>>>& edges)
{

    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u = edges[i].first;
        int v = edges[i].second.first;
        int wt = edges[i].second.second;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }


    priority_queue<p, vector<p>, greater<p>> pq;


    vector<bool> visited(V, false);


    int sum = 0;


    pq.push({0, 0});


    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        if(visited[u] == true){
            continue;
        }

        sum=sum+wt;
        visited[u] = true;


        for(auto v : adj[u]){

            if(visited[v.first] == false){
                pq.push({v.second, v.first});
            }
        }
    }

    return sum;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < E; i++) {
        int00 wt;
        cin >> u >> v >> wt;
        edges.push_back({u, {v, wt}});
    }


    cout << spanningTree(V, E, edges) << endl;

    return 0;
}

