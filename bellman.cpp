
#include<bits/stdc++.h>
using namespace std;
int N=100000000000;
vector<pair<int,int>> graph[20];
vector<int>dist(30,N);
void printGraph(int n){
	for(int i=0;i<n;i++){
		cout<<i<<"-> ";
		for(int j=0;j<graph[i].size();j++){
			cout<<graph[i][j].first<<" "<<graph[i][j].second<<" ";
		}
		cout<<endl<<endl;;
	}

}
void bellman_ford(int source,int v){
    dist[source]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<graph[j].size();k++){
                auto edge=graph[j][k];
                if(dist[edge.first]>dist[j]+edge.second){
                    dist[edge.first]=dist[j]+edge.second;
                }
            }
        }
    }
}
int main(){
    int n,e;
    cout<<"number of vertex and edge"<<endl;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int v1,v2,wt;
		cin>>v1>>v2>>wt;
		graph[v1].push_back(make_pair(v2,wt));

	}
    bellman_ford(0,n);
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}
