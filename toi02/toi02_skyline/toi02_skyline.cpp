#include <cstdio>
//toi2_skyline
//brute force
int a[256], mx;
signed main(){
    int n, l, h, r; scanf("%d", &n);
    while(n--){
        scanf("%d %d %d", &l, &h, &r);
        if(r > mx) mx = r;
        for(int i = l; i<r; ++i) if(h > a[i]) a[i] = h; // range maximum update
    }
    for(int i = 1; i<=mx; ++i) if(a[i] ^ a[i-1]) printf("%d %d ", i, a[i]); 
}
