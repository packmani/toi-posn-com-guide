//toi15_budget
//MST + binary search
#include <cstdio>
#include <algorithm>
#include <tuple>
using namespace std;
int p[3000], sz[3000], dp[1000005];
pair<int,int> pk[1000005];
tuple<int,int,int> Edge[500000];
int fp(int x){if(x == p[x]) return x; return p[x] = fp(p[x]);}
void U(int u, int v){
    u = fp(u); v = fp(v); if(u == v) return; if(sz[u] < sz[v]) swap(u, v); sz[u] += sz[v]; p[v] = u;
}
signed main(){
    int B, E; scanf("%d %d", &B, &E);
    for(int i = 0; i<B; ++i){p[i] = i; sz[i] = 1;} //initialize
    for(int i = 0, s, t, l, r; i<E; ++i){
        scanf("%d %d %d %d", &s, &t, &l, &r); 
        if(r) U(s, t);//already have roof -> add to graph
        else Edge[i] = make_tuple(l, s, t); 
    }
    int P; scanf("%d", &P); // number of packages
    for(int i = 0, C, D; i<P; ++i){
        scanf("%d %d", &C, &D);
        pk[i] = make_pair(C, D); //{length, price}
    }
    sort(pk, pk+P); //sort by length
    dp[P-1] = pk[P-1].second; //base case
    for(int i = P-2; i>=0; --i) dp[i] = min(pk[i].second, dp[i+1]);
    sort(Edge, Edge+E); //sort by increasing order of weight
    long long tot = 0;
    //Kruskal's
    for(int i = 0, l, s, t; i<E; ++i){
        tie(l, s, t) = Edge[i];
        if(fp(s) != fp(t)){
            U(s, t);
            int w = l, j = lower_bound(pk, pk+P, make_pair(w, -1)) - pk; 
            tot += dp[j];
        }
    }
    printf("%lld", tot);
}
