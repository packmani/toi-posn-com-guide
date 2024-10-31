//toi5_jump
//two-pointers
#include <cstdio>
int x[30000];
signed main(){
    int n, k, mx = 0; scanf("%d %d", &n, &k);
    for(int i = 0; i<n; ++i) scanf("%d", x+i); // x is sorted
    for(int l = 0, r = 0; l<n; ++l){ //the bound of each l (r) is non-decreasing (r_0 <= r_1 <= r_2 <= r_3 <= ... <= r_{n-1})
        for(; r<n && x[l] >= x[r]-k; ++r){} //increase r until out of [x, x+k]
        if(r-l-1 > mx) mx = r-l-1; //keep the maximum length
    }
    printf("%d", mx);
}
