#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];

void make(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    int n;
    int m;

    cin >> n >> m;

    make(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    map<int, int> number;

    for (int i = 0; i < n; i++) {
        int root = find(i);
        number[root]++;
    }

    for (int i = 1; i <=n; i++) {
        int root = find(i);
        cout<< i <<" -> " << number[root] << endl;
    }

    return 0;
}

