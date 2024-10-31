//toi13_orchid
//LIS using binary search
#include <cstdio>
#include <algorithm>
int LIS[1000001];
signed main(){
    int n, sz = 0; scanf("%d", &n);
    for(int i = 0, h, idx; i<n; ++i){
        scanf("%d", &h);
        LIS[idx = std::upper_bound(LIS, LIS+sz, h) - LIS] = h; // non-decreasing
        if(idx == sz) ++sz;
    }
    printf("%d", n - sz);
}
