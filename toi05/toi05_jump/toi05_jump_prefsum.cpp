//toi5_jump
//prefix sum
#include <cstdio>
#include <algorithm>
int qs[60001], x[30000], n, k, mx = 0; 
signed main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i<n; ++i){
        scanf("%d", x+i); ++qs[x[i]]; //add line x[i]
    }
    for(int i = 1; i<=x[n-1]; ++i) qs[i] += qs[i-1]; //prefix sum
    for(int i = 0; i<n; ++i) mx = std::max(mx, qs[std::min(x[n-1], x[i]+k)] - qs[x[i]]); //find sum in range [x[i]+k, x[i]) 
    printf("%d", mx);
}
