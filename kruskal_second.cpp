#include <bits/stdc++.h>
using namespace std;
const int N=1e3;
int parent[N];
int size[N];
void make_set(int v){
	parent[v]=v;
	size[v]=1;
}
int find_set(int v){
	if(parent[v]==v) return v;
	return parent[v]=find_set(parent[v]);
}
void union_set(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b){
		if(size[a]<size[b]) swap(a,b);
		parent[b]=a;
		size[a]+=size[b];
	}
}

struct edge{
	int u,v,wt;
	bool operator<(const edge e){
		return wt<e.wt;
	}
};

vector<edge> edgelist;
vector<edge> s_b_mst;

int kruskal_algo(int n,vector<edge>&mst){
    int cost=0;
	for(int i=0;i<n;i++) make_set(i);

	sort(edgelist.begin(),edgelist.end());

	for(auto val: edgelist){
		if(find_set(val.u)!=find_set(val.v)){
			cost+=val.wt;
			mst.push_back(val);
			union_set(val.u,val.v);
		}
	}
    return cost;
}

void second_best_mst(int n){

    int cost=kruskal_algo(n,s_b_mst);
	cout<<cost<<endl;

    vector<edge> temp;
	int min_cost=1e3;
	for(int i=0;i<s_b_mst.size();i++){
		int calc_cost;

		for(int j=0;j<n;j++){
			parent[i]=0;
			size[i]=0;
		}

		edge p=s_b_mst[i];
		for(auto it=edgelist.begin();it!=edgelist.end();it++){
			if((*it).u== p.u && (*it).v==p.v && (*it).wt==p.wt){
				edgelist.erase(it);
			}
		}
        calc_cost=kruskal_algo(n,temp);
        if(calc_cost<min_cost) {
			min_cost=calc_cost;
		}
        edgelist.push_back(p);
	}

    cout<<min_cost<<endl;
}
main(){
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge e;
		e.u=u;
		e.v=v;
		e.wt=w;
		edgelist.push_back(e);
	}
	second_best_mst(n);
}
