#include<iostream>


using namespace std;

const int N=1ef;



void make()
{
    for(int i=0;i<v;i++)
        parent[v]=i;
}
int find()
{
    if(parent[v]=v) return v;
    return parent[v]=find parent(parent[v]);
}
void unionn()
{
    a=parent[a];
    b=parent[b];
    if(a!b)
        parent[b]=a;

}
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

    map<int, int> numberOfFriends;

    for (int i = 0; i < n; i++) {
        int root = find(i);
        numberOfFriends[root]++;
    }

    for (int i = 0; i < n; i++) {
        int root = find(i);
        cout << "Vertex " << i << " belongs to the component with " << numberOfFriends[root]






int main()
{
    int n,m;
    cin>>n;
    cin>>m;

    for


    return 0;
}
