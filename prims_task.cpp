#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
typedef long long ll;

const int MAXN = 100005; // Set this to your desired maximum number of vertices

vector<pair<int, int>> adj[MAXN]; // Adjacency list representation of the graph
bool vis[MAXN] = {false};

ll Prims(int src, int includeEdgeSrc, int includeEdgeDest, int includeEdgeWeight) {
    ll cost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        int ct = p.first;

        if (vis[u]) continue;
        vis[u] = true;

        cost += ct;

        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!vis[v]) {
                pq.push({w, v});
            }
        }
    }

    // Include the particular edge if it's not already in the MST
    if (src != includeEdgeSrc) {
        cost += includeEdgeWeight;
    }

    return cost;
}

int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int includeEdgeSrc, includeEdgeDest, includeEdgeWeight;
    cin >> includeEdgeSrc >> includeEdgeDest >> includeEdgeWeight;

    ll minimumSpanningTreeCost = Prims(1, includeEdgeSrc, includeEdgeDest, includeEdgeWeight);
    cout << "Minimum Spanning Tree Cost: " << minimumSpanningTreeCost << endl;

    return 0;
}

