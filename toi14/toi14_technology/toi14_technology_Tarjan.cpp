#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#define N 100000
#define K 10000
std::vector<int> g[N];
std::set<int> V[K];
std::queue<int> q;
int l[N], stk[N], tin[N], low[N], vis[N], SZ[N], C[N], c, sz, ti = 1, ok = 1;
void dfs(int u){ 
    vis[stk[sz++] = u] = 1; tin[u] = low[u] = ti++;
    for(int v: g[u]){
        if(!tin[v]){
        	dfs(v);
        	if(low[v] < low[u]) low[u] = low[v];
        }else if(vis[v] && tin[v] < low[u]) low[u] = tin[v]; 
    }
    if(low[u] == tin[u]){
        do{
            vis[stk[sz-1]] = 0; ++SZ[C[stk[--sz]] = c];
        }while(stk[sz] != u);
        ++c;
    }
}
signed main(){
	int n, k, t, Ans = -1; scanf("%d %d %d", &n, &k, &t);
	for(int i = 0, x; i<n; ++i){
		scanf("%d %d", l+i, &sz); V[--l[i]].insert(i);
		while(sz--) scanf("%d", &x), g[i].push_back(--x);
	}
	for(int i = sz = 0; i<n; ++i) if(!tin[i]) dfs(i);
	for(int i = 0; i<n; vis[i++] = 0);
	for(int i = 0, cnt = 0; i<k; Ans = ++i){
		for(int u: V[i]){
			if(SZ[C[u]] > 1 || (cnt += (vis[u] = 1)) > t){ ok = 0; break;} 
			q.push(u);
		}
		while(ok && !q.empty()){
			int u = q.front(); q.pop();
			for(int v: g[u]){
				if(!vis[v]){
					if(SZ[C[v]] > 1 || (cnt += (vis[v] = 1)) > t){ ok = 0; break;} 
					q.push(v); V[l[v]].erase(v);
				}
			}
		}
		if(!ok) break;
	}
	printf("%d", Ans);
}
