//toi18_garden
//fenwick tree
#include <cstdio>
#include <algorithm>
using namespace std;
int LIS[2][200000], bit[200001], cp[200000], m = 0, n, q, h[200000];
void upd(int i, int val){for(; i<=m; i+=i&-i) bit[i] = max(bit[i], val);}
int qry(int i){int res = 0; for(; i; i-=i&-i) res = max(res, bit[i]); return res;}
signed main(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i<n; ++i){scanf("%d", h+i); cp[m++] = h[i];}
    sort(cp, cp+m); m = unique(cp, cp+m) - cp; // coordinate compression (compress index)
    for(int i = 0; i<n; ++i) h[i] = upper_bound(cp, cp+m, h[i]) - cp;
    for(int i = 0; i<n; ++i) upd(h[i], LIS[0][i] = qry(h[i]-1) + 1); // LIS from front
    fill(bit, bit+m+1, 0);
    for(int i = n-1; i>=0; --i) upd(h[i], LIS[1][i] = qry(h[i]-1) + 1); // LIS from back
    while(q--){
        int X; scanf("%d", &X);
        int kl = LIS[0][X] - 1, kr = LIS[1][X] - 1;
        printf("%d\n", min(kl, kr));
    }
}
