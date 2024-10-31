//toi8_electricity
//segment tree
#include <cstdio>
#include <algorithm>
int s[2000005], dp, idx, L, R;
void upd(int ind, int low, int high){
    if(low == high){s[ind] = dp; return;}
    int mid = low + ((high-low)>>1);
    if(idx <= mid) upd(ind<<1, low, mid);
    else upd(ind<<1|1, mid+1, high);
    s[ind] = std::min(s[ind<<1], s[ind<<1|1]);
}
int qry(int ind, int low, int high){
    if(low > R || high < L) return 1e9;
    if(L <= low && high <= R) return s[ind];
    int mid = low + ((high-low)>>1);
    return std::min(qry(ind<<1, low, mid), qry(ind<<1|1, mid+1, high));
}
signed main(){
    int n, k; scanf("%d %d", &n, &k); 
    std::fill(s, s+(n<<2), 1e9);
    for(int i = 0, p; i<n; ++i){
        scanf("%d", &p); idx = i; L = std::max(0, i-k); R = i-1;
        dp = p + ((L <= R)? qry(1, 0, n-1) : 0); // qry -> minimum in range [i-k, i-1] 
        upd(1, 0, n-1);
    }
    printf("%d", dp);  
}
