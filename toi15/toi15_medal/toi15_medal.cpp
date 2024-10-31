//toi15_medal
//greedy
#include <cstdio>
#include <algorithm>
typedef long long ll;
int t[500000], h[500000];
signed main(){
    int n; scanf("%d", &n);
    for(int i = 0; i<n; ++i) scanf("%d", t+i);
    for(int i = 0; i<n; ++i){scanf("%d", h+i); h[i] = -h[i];}
    std::sort(t, t+n); std::sort(h, h+n);
    ll mx = 0, mn = 1e18;
    for(int i = 0; i<n; ++i){
        ll tmp = (ll)t[i] - (ll)h[i];
        if(tmp > mx) mx = tmp;
        if(tmp < mn) mn = tmp;
     }
    printf("%lld", mx - mn);
}
