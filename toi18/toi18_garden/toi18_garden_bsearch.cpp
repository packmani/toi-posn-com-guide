//toi18_garden
//binary search
#include <cstdio>
#include <algorithm>
using namespace std;
int V[200000], h[200000], LIS[2][200000];
signed main(){
    int n, q, sz = 0; scanf("%d %d", &n, &q);
    for(int i = 0; i<n; ++i) scanf("%d", h+i);
    // LIS from front
    for(int i = 0; i<n; ++i){
        V[LIS[0][i] = lower_bound(V, V+sz, h[i]) - V] = h[i];
        if(LIS[0][i] == sz) ++sz;
    }
    sz = 0;
    // LIS from back
    for(int i = n-1; i>=0; --i){
        V[LIS[1][i] = lower_bound(V, V+sz, h[i]) - V] = h[i];
        if(LIS[1][i] == sz) ++sz;
    }
    while(q--){
        int X; scanf("%d", &X);
        printf("%d\n", min(LIS[0][X], LIS[1][X])); // k = min(kl, kr)
     }
}
