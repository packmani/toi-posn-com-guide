//toi1_pattern
//brute force
#include <iostream>
#include <bitset>
std::bitset<71> a[50001]; //true if this cell (i, j) is 'x'
signed main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, mx = 0, p, q, r; std::cin>>n;
    while(n--){
        std::cin>>p>>q>>r; mx = std::max(mx, p);
        for(int j = q; j<=std::min(70, q+r-1); ++j) a[p][j] = true;
    }
    for(int i = 1; i<=mx; ++i){
        for(int j = 1; j<=70; ++j){
            if(a[i][j]) std::cout<<'x';
            else std::cout<<'o';
        }
        std::cout<<'\\n';
    }
}
