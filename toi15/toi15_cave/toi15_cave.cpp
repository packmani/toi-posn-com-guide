//toi15_cave
//dijkstra -> states {no of steps, current node} 
#include <cstdio>
#include <algorithm>
#include <queue>
#include <tuple>
typedef long long ll;
ll D[2000][2000];
bool vis[2000][2000];
std::vector<std::pair<int,int>> g[2000];
const ll inf = 1e15;
signed main(){
    int n, p, u, e; scanf("%d %d %d %d", &n, &p, &u, &e);
    while(e--){
        int q, r, t; scanf("%d %d %d", &q, &r, &t);
        if(r != p) g[q].emplace_back(t, r);
    }
    using T = std::tuple<ll,int,int>;
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    for(int st = 0; st<n; ++st) std::fill(D[st], D[st]+n, inf);
    pq.emplace(D[0][p] = 0, 0, p); 
    //dijkstra
    while(!pq.empty()){
        ll dis; int st, u; std::tie(dis, st, u) = pq.top(); pq.pop();
        if(vis[st][u]) continue; vis[st][u] = true;
        for(std::pair<int,int> it: g[u]){
            int w = it.first, v = it.second;
            if(st+1 < n && D[st][u] + w < D[st+1][v]) pq.emplace(D[st+1][v] = D[st][u] + w, st+1, v);
        }
    }
    ll pf = inf;
    std::vector<std::pair<ll,int>> d;
    for(int st = 0; st<n; ++st){
        if(D[st][u] < pf){d.emplace_back(D[st][u], st); pf = D[st][u];} 
        // D[j][u] is only maybe better when D[j][u] < all D[i][u], i < j
    }
    int L; scanf("%d", &L);
    while(L--){
        ll h, mn = inf; scanf("%lld", &h);
        for(std::pair<ll,int> it: d) mn = std::min(mn, it.first + (it.second-1) * h); //run through possibilities
        printf("%lld ", mn);
    }
}
