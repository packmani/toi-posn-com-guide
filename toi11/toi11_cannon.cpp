//toi11_cannon
#include <cstdio>
#include <algorithm>
int qs[10000005], mn = 9999999, mx = 0; // qs -> prefix sum
int sum(int l, int r){return qs[r] - ((l)? qs[l-1] : 0);}
signed main(){
    int n, m, k, l; scanf("%d %d %d %d", &n, &m, &k, &l);
    for(int i = 0, x; i<n; ++i){
        scanf("%d", &x); ++qs[x]; 
        mx = std::max(mx, x);
        mn = std::min(mn, x);
    }    
    for(int i = mn+1; i<=mx; ++i) qs[i] += qs[i-1];
    while(k--){
        int cnt = 0, R = mn;
        for(int i = 0, x; i<m; ++i){
            scanf("%d", &x);
            int lb = std::max(x-l, R);
            int rb = std::min(x+l, mx);
            //find number of cannon in range [lb, rb] that does not overlap to any previous range
            if(lb <= rb) cnt += sum(lb, rb); 
            R = std::max(R, rb+1);
        }
        printf("%d\n", cnt);
    }
}
