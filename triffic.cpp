#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAX_N = 205;
const int INF = INT_MAX;

class Edge {
    public:
    int from, to;
};

int n, q;
int busyness[MAX_N];
vector<Edge> edges;

vector<int> bellmanFord(int source) {
    vector<int> dist(n + 1, INF);
    dist[source] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        for (const Edge &edge : edges) {
            int from = edge.from;
            int to = edge.to;
            int earning = busyness[to] - busyness[from];
            dist[to] = min(dist[to], dist[from] + earning);
        }
    }

    vector<int> result;
    for (int i = 1; i <= q; ++i) {
        int junction;
        cin >> junction;
        result.push_back(dist[junction]);
    }
    return result;
}

int main() {
    int setNumber = 1;

    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> busyness[i];
        }

        int r;
        cin >> r;
        edges.clear();
        for (int i = 0; i < r; ++i) {
            int source, destination;
            cin >> source >> destination;
            edges.push_back({source, destination});
        }

        cin >> q;
        cout << "Set #" << setNumber++ << endl;
        vector<int> results = bellmanFord(1);

        for (int result : results) {
            if (result >= 3 && result != INF) {
                cout << result << endl;
            } else {
                cout << "?" << endl;
            }
        }
    }

    return 0;
}
