//toi2_maxseq
//prefix sum
#include <cstdio>
#include <algorithm>
using namespace std;
int a[2501];
signed main(){
    int n, prf_sum = 0/*prefix sum*/, mx_sum = 0, st/*start seq idx*/, ed/*end seq idx*/; scanf("%d", &n);
    pair<int,int> mn = make_pair(0, 0);
    //sum in range prefix sum 
    //sum[l, r] = qs[r] - qs[l-1]
    //we want to maximize sum(l, r) -> choose minimum qs[l-1]
    for(int i = 1, x; i<=n; ++i){
        scanf("%d", &x); a[i] = x;
        prf_sum += x;
        if(make_pair(prf_sum - mn.first, -(mn.second + 1)) > make_pair(mx_sum, -st)){mx_sum = prf_sum - mn.first; st = mn.second + 1; ed = i;}
        mn = min(mn, make_pair(prf_sum, i)); //keep minimum of prefix sum (to find mimum mum qs[l-1])
    }
    if(mx_sum){for(int i = st; i<=ed; ++i) printf("%d ", a[i]); printf("\n%d", mx_sum);}
    else puts("Empty sequence");
}    
