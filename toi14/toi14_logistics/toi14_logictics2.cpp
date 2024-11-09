#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
ll p[N], D[N][N][2];
bool vis[N][N][2];
using pli = pair<ll,int>;
const ll inf = 1e15;
vector<pli> adj[N];
signed main(){
    int n; scanf("%d", &n);
    for(int i = 0; i<n; ++i) scanf("%lld", p+i);
    int s, d, f; scanf("%d %d %d", &s, &d, &f); --s; --d; 
    int m; scanf("%d", &m);
    for(int i = 0, u, v, w; i<m; ++i){
        scanf("%d %d %d", &u, &v, &w); --u; --v;
        adj[u].emplace_back(w, v); adj[v].emplace_back(w, u);
    }
    for(int i = 0; i<n; ++i) for(int j = 0; j<=f; ++j) for(int k = 0; k<2; ++k) D[i][j][k] = inf;
    using T = tuple<ll,int,int,bool>;
    priority_queue<T, vector<T>, greater<T>>pq;
    pq.emplace(D[s][0][false] = 0, s, 0, false); //source
    while(!pq.empty()){
        ll dis; int u, uf; bool used; tie(dis, u, uf, used) = pq.top(); pq.pop();
        if(vis[u][uf][used]) continue; vis[u][uf][used] = true;
        if(uf < f && D[u][uf][used] + p[u] < D[u][uf+1][used]) pq.emplace(D[u][uf+1][used] = D[u][uf][used] + p[u], u, uf+1, used); //pay for the fuel
        if(!used){ //fuel for free 
            if(D[u][uf][false] < D[u][f][true]) pq.emplace(D[u][f][true] = D[u][uf][false], u, f, true);
        }
        for(pli it: adj[u]){ //walk from u -> v
            ll w = it.first; int v = it.second;
            if(uf>=w && D[u][uf][used] < D[v][uf-w][used]) pq.emplace(D[v][uf-w][used] = D[u][uf][used], v, uf-w, used);
        }
    }
    printf("%lld", D[d][f][true]); //Ans
}
