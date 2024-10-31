//toi11_place
//maximum spanning tree using Prim's 
#include <cstdio>
#include <queue>
using namespace std;
vector<pair<int,int>> g[200000];
long long D[200000];
bool vis[200000];
signed main(){
    int n, m; scanf("%d %d", &n, &m);
    while(m--){
        int u, v, w; scanf("%d %d %d", &u, &v, &w); --u; --v; --w;
        g[u].emplace_back(w, v); g[v].emplace_back(w, u);
    }
    fill(D, D+n, -1e18); //fill with -inf
    priority_queue<pair<long long, int>> pq;
    pq.emplace(D[0] = 0, 0); //start with random node
    long long MST = 0;
    //Prim's
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        if(vis[u]) continue; vis[u] = true;
        MST += D[u];
        for(pair<int,int> it: g[u]){
            int w = it.first, v = it.second;
            if(!vis[v] && w > D[v]) pq.emplace(D[v] = w, v);
        }
    }
    printf("%lld", MST);
}
