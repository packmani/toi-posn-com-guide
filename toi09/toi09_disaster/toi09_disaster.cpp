//toi9_disaster
//find an eulerian path
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
bool vis[300];
vector<pair<int,int>> g[26];
void dfs(int u, int i){
    if(i >= 0) vis[i] = true;
    for(pair<int,int> it: g[u]){
        int v = it.first, j = it.second;
        if(!vis[j]) dfs(v, j);
    }
    printf("%c ", u+'A');
}
signed main(){
    int n, mx = 0, src = 0; scanf("%d", &n); char x, y;
    for(int i = 0, u, v; i<n; ++i){
        scanf(" %c %c", &x, &y); 
        u = x-'A'; v = y-'A'; mx = max(mx, max(u, v));
        g[u].emplace_back(v, i); g[v].emplace_back(u, i);
    }
    for(int i = 0; i<=mx; ++i) if(g[i].size() & 1){src = i; break;}
    dfs(src, -1);
}    
