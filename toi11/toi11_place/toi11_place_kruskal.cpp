//toi11_place
//maximum spanning tree using Kruskal's
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <functional>
int sz[200000], p[200000];
std::tuple<int,int,int> E[1000000];
int fp(int x){if(x == p[x]) return x; return p[x] = fp(p[x]);} //find root
signed main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0; i<n; ++i){p[i] = i; sz[i] = 1;}
    for(int i = 0; i<m; ++i){
        int u, v, w; scanf("%d %d %d", &u, &v, &w); 
        E[i] = std::make_tuple(w-1, u-1, v-1);
    } 
    std::sort(E, E+m, std::greater<std::tuple<int,int,int>>()); //sort by weight in descending order
    long long MST = 0;
    for(int i = 0; i<m; ++i){
        int w, u, v; std::tie(w, u, v) = E[i];
        if(fp(u) != fp(v)){
            //Union
            u = fp(u); v = fp(v); MST += w;
            if(sz[u] < sz[v]) std::swap(u, v);
            sz[u] += sz[v]; p[v] = u;
        }
    }
    printf("%lld", MST);
}
