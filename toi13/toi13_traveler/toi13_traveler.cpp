//toi13_traveler
//dijkstra
#include <cstdio>
#include <queue>
typedef long long ll;
using namespace std;
vector<pair<int,int>> adj[10000];
ll D[2][10000]; bool vis[10000]; int n;
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
//dijkstra
void dij(int x, int src){
    fill(D[x], D[x]+n, 1e18); fill(vis, vis+n, false);
    pq.emplace(D[x][src] = 0, src);
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        if(vis[u]) continue; vis[u] = true;
        for(pair<int,int> it: adj[u]){
            int w = it.first, v = it.second;
            if(D[x][u] < 1e18 && !vis[v] && D[x][u] + w < D[x][v]) pq.emplace(D[x][v] = D[x][u] + w, v);
        }
    }
}
signed main(){
    int m, x, y, z; scanf("%d %d %d %d %d", &n, &m, &x, &y, &z);
    for(int i = 0, u, v, w; i<m; ++i){
        scanf("%d %d %d", &u, &v, &w); adj[u].emplace_back(w, v); adj[v].emplace_back(w, u);
    } 
    dij(0, x); dij(1, y); //dijkstra from both ends
    if(D[0][y] <= z){
        printf("%d %lld 0", y, D[0][y]);
    }else{
        //if cannot go directly to y
        ll nearest = 1e18; int k;
        //loop from back to front gurantee smallest city index
        for(int i = n-1; i>=0; --i) if(D[0][i] <= z && D[1][i] <= nearest){nearest = D[1][i]; k = i;} //keep the nearest city to y
        printf("%d %lld %lld", k, D[0][k], D[1][k]); 
    }

}
