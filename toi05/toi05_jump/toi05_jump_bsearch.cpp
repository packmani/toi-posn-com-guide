//toi5_jump 
//binary search
#include <cstdio>
#include <algorithm>
int x[30000];
signed main(){
    int n, k, mx = 0; scanf("%d %d", &n, &k);
    for(int i = 0; i<n; ++i){
        scanf("%d", x+i);
        int j = std::lower_bound(x, x+i, x[i]-k) - x; //j is the first index that >= x[i] - k
        mx = std::max(mx, i - j); //keep maximum
    }
    printf("%d", mx);
}
