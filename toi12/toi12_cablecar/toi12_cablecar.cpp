//toi12_cablecar
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int sz[2500], par[2500];
tuple<int,int,int> E[1000000];
int fp(int x){return (x == par[x])? x : par[x] = fp(par[x]);}
signed main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0; i<n; ++i){par[i] = i; sz[i] = 1;}
    for(int i = 0; i<m; ++i){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        E[i] = make_tuple(w, --u, --v);
    }
    int s, d, p, mn; scanf("%d %d %d", &s, &d, &p); --s; --d;
    sort(E, E+m, greater<tuple<int,int,int>>());
    for(int i = 0, w, u, v; i<m; ++i){
        tie(w, u, v) = E[i];
        if(fp(s) == fp(d)) break;
        if(fp(u) != fp(v)){
            mn = w; u = fp(u); v = fp(v);
            if(sz[u] < sz[v]) swap(u, v);
            sz[u] += sz[v]; par[v] = u;
        }
    }
    printf("%d", p/(mn-1) + (p % (mn-1) != 0));
}
