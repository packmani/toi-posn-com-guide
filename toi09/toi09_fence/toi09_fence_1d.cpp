//toi9_fence
//vertical and horizontal prefix sum
//one-based index
#include <cstdio>
#include <cstring>
#include <algorithm>
int qs[2][501][501];
signed main(){    
    int tc = 2, m, n, t;
    while(tc--){
        scanf("%d %d %d", &m, &n, &t);
        memset(qs, 0, sizeof(qs));
        for(int i, j; t--; ){scanf("%d %d", &i, &j); ++i; ++j; qs[0][i][j] = qs[1][j][i] = 1;}
        for(int i = 1; i<=m; ++i) for(int j = 1; j<=n; ++j) qs[0][i][j] += qs[0][i][j-1];
        for(int j = 1; j<=n; ++j) for(int i = 1; i<=m; ++i) qs[1][j][i] += qs[1][j][i-1];
        bool ch = false;
        for(int k = std::min(m, n); k; --k){
            for(int i = k; i<=m; ++i){
                for(int j = k; j<=n; ++j){
                    int h1 = qs[0][i][j] - qs[0][i][j-k]; if(h1) continue;
                    int h2 = qs[0][i-k+1][j] - qs[0][i-k+1][j-k]; if(h2) continue;
                    int v1 = qs[1][j][i] - qs[1][j][i-k]; if(v1) continue;
                    int v2 = qs[1][j-k+1][i]- qs[1][j-k+1][i-k]; if(v2) continue;
                    printf("%d\n", k); ch = true; break;
                }
                if(ch) break;
            }
            if(ch) break;
        }
    }
}
