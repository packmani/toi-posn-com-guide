//toi12_weakpoint
//cycle detection + dp on tree
#include <cstdio>
#include <vector>
const int N = 500000;
std::vector<int> g[N];
int up[N], C[N], vis[N], cyc[N], sz[N], mx, x, c; // C[i] check if node i is on cycle?
void dfs(int u, int p){ //detect cycle
    vis[u] = 1; up[u] = p;
    for(int v: g[u]){
        if(v != p){
            if(!vis[v]) dfs(v, u);
            else if(vis[v] == 1){ //u -> v is a backedge
                for(x = u; x != v; x = up[x]){ cyc[c++] = x; C[x] = 1;} cyc[c++] = v; C[v] = 1;
            }
        }
    }
    vis[u] = 2;
}
void efs(int u, int p){
    sz[u] = 1; up[u] = p;
    for(int v: g[u]){
        if(v == p || C[v]) continue;
        efs(v, u); sz[u] += sz[v];
    }
}
signed main(){
    int n, m; scanf("%d %d", &n, &m); --m;
    for(int i = 0, u, v; i<n; ++i){
        scanf("%d %d", &u, &v); --u; --v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(0, 0);
    for(int i = 0; i<c; ++i) efs(cyc[i], cyc[i]); //dfs to find subtree size, dfs from roots (nodes on cycle)
    x = n;
    if(!C[m]){ // m is not on the cycle
        mx = n - sz[m] - 1; x = up[m]; // x = parent of u (p)
        for(int v: g[m]){ // check children
            if(v != up[m]) if(sz[v] - 1 > mx || (sz[v] - 1 == mx && v < x)) mx = sz[x = v] - 1;
        }
    }else{ // m is on the cycle
        for(int v: g[m]){ // check children
            if(!C[v]) if(sz[v] - 1 > mx || (sz[v] - 1 == mx && v < x)) mx = sz[x = v] - 1;
        }
        for(int i = 0; i<c; ++i){ // check other cycle nodes
            int v = cyc[i];
            if(v != m && (sz[v] - 1 > mx || (sz[v] - 1 == mx && v < x))) mx = sz[x = v] - 1;
        }
    }
    printf("%d\n%d", x + 1, mx);
}
