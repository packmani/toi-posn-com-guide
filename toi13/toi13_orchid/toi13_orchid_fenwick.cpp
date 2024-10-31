//toi13_orchid
//LIS using fenwick tree
#include <cstdio>
#include <algorithm>
int bit[1000001]; 
void upd(int i, int val){for(; i<=1e6; i+=i&-i) bit[i] = std::max(bit[i], val);}
int qry(int i){int res = 0; for(; i; i-=i&-i) res = std::max(res, bit[i]); return res;}
signed main(){
    int n, LIS = 0; scanf("%d", &n);
    for(int i = 0, h, lis; i<n; ++i){
        scanf("%d", &h);
        LIS = std::max(LIS, lis = qry(h) + 1); // qry(h) find max in range [1, h]
        upd(h, lis);
    }
    printf("%d", n - LIS);
}
