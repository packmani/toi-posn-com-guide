//toi6_jail
//fenwick tree + binary lifing on fenwick tree (kth element)
#include <stdio.h>
int n, cnt, LG, bit[1000001];
void upd(int i, int v){ for(; i<=n; i+=i&-i) bit[i] += v;}
int _find(int k){ 
    int i = 0, sum = 0;
    for(int j = LG; ~j; --j) if(i+(1<<j) <= n && sum + bit[i+(1<<j)] < k) sum += bit[i+=(1<<j)];
    return i+1;
}
signed main(){
    int k, t; scanf("%d %d", &n, &k); 
    --k; LG = 32 - __builtin_clz(n);
    for(int i = 1; i<=n; ++i) upd(i, 1);
    int sz = n, p = k%n;
    while(1){
        printf("%d ", t = _find(p+1));
        if(++cnt == n) break;
        upd(t, -1);
        if((p += k) >= (--sz)) p %= sz;
    }
}
