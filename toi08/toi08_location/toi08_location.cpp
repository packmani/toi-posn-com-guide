//toi8_location
//2D prefix sum
#include <cstdio>
#include <algorithm>
int m, n, k,  qs[1000][1000];
int f(int i, int j){if(i >= 0 && j >= 0 && i<m && j<n) return qs[i][j]; return 0;}
signed main(){
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i<m; ++i) for(int j = 0; j<n; ++j) scanf("%d", &qs[i][j]);
    for(int i = 0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            if(i) qs[i][j] += qs[i-1][j];
            if(j) qs[i][j] += qs[i][j-1];
            if(i && j) qs[i][j] -= qs[i-1][j-1];
        }
    }
    int mx = 0;
    for(int i = k-1; i<m; ++i){
        for(int j = k-1; j<n; ++j){
            mx = std::max(mx, f(i, j) - f(i-k, j) - f(i, j-k) + f(i-k, j-k));
        }
    }
    printf("%d", mx);
}
