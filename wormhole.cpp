#include <bits/stdc++.h>
 using namespace std;
  const int max_e=2005;
  const int max_v=1005;
class edge {
    public:
    int from,to,cost;};
edge es[max_e];
int d[max_v];
int v,e;
    bool Find_negative_loop () {memset (d,0,sizeof (d));
            for (int i=0;i<v;i++) {for (int j=0;j<e;j++) {edge e=es[j];
                if (d[e.to]>d[e.from]+e.cost) {d[e.to]=d[e.from]+e.cost;
            if (i==v-1) return true;
}}} return false;
    } int main () {ios::sync_with_stdio (false);
    int t;
    cin>>t;
        while (t--) {cin>>v>>e;
        for (int i=0;i<e;i++) cin>>es[i].from>>es[i].to>>es[i].cost;
        if (Find_negative_loop ()) cout<< "Possible" <<endl;
    else cout<< "not possible" <<endl;
} return 0; }
