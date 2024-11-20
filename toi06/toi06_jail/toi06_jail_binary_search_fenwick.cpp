//toi6_jail
//fenwick tree + binary search
#include <stdio.h>
int n, cnt, bit[1000001];
void upd(int i, int v){ for(; i<=n; i+=i&-i) bit[i] += v;}
int qry(int i){ int r = 0; for(; i; i-=i&-i) r += bit[i]; return r;}
//qry(i+1) >= qry(i)
int _find(int k){
    int low = 1, high = n, j;
    while(low <= high){
        int mid = low + ((high-low)>>1);
        if(qry(mid) >= k) high = (j = mid) - 1;
        else low = mid+1;
    }
    return j;
}
signed main(){
    int k, t; scanf("%d %d", &n, &k); --k;
    for(int i = 1; i<=n; ++i) upd(i, 1);
    int sz = n, p = k%n;
    while(1){
        printf("%d ", t = _find(p+1));
        if(++cnt == n) break;
        upd(t, -1);
        if((p += k) >= (--sz)) p %= sz;
    }
}
