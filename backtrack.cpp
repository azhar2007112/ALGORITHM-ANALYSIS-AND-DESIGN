#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void tspBacktrack(int node, int depth, int cost, int v,
                  vector<int>& path, vector<bool>& visited,
                  vector<int>& minimumPath, int& minCost,
                  vector<vector<int>>& graph) {
    if (depth == v) {
        if (cost < minCost) {
            minCost = cost;
            minimumPath = path;
        }
        return;
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            path[depth] = i;
            visited[i] = true;

            tspBacktrack(i, depth + 1, cost + graph[node][i], v, path, visited, minimumPath, minCost, graph);

            visited[i] = false;
        }
    }
}

int calculateTotalCost(const vector<int>& path, const vector<vector<int>>& graph) {
    int totalCost = 0;
    int v = path.size();

    for (int i = 0; i < v - 1; i++) {
        totalCost += graph[path[i]][path[i + 1]];
    }

    totalCost += graph[path[v - 1]][path[0]];

    return totalCost;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v, vector<int>(v, INF));
    vector<int> path(v);
    vector<bool> visited(v, false);
    vector<int> minimumPath;
    int minCost = INF;

    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x - 1][y - 1] = w;
        graph[y - 1][x - 1] = w;
    }

    tspBacktrack(0, 0, 0, v, path, visited, minimumPath, minCost, graph);

    cout << "Minimum Cost: " << minCost << endl;
    cout << "Path: ";
    for (int i = 0; i < v; i++) {
        cout << minimumPath[i] + 1 << " ";
    }
    cout << minimumPath[0] + 1 << endl;

    cout << "Total Cost: " << calculateTotalCost(minimumPath, graph) << endl;
}
