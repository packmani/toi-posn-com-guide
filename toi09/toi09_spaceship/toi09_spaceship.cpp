//toi9_spaceship
//bitmask dynamic programming
#include <cstdio>
#include <algorithm>
using namespace std;
int x[11], y[11], z[11], M[11], K[11], C[11], dp[2048][11];
//dp[mask][u] - minimum distance from start if we have visited shops presented in mask and we are in u shop
int sq(int a){return a*a;}
signed main(){
    int n, m; scanf("%d", &n);
    scanf("%d %d %d %d", x+0, y+0, z+0, &m);
    for(int i = 1; i<=m; ++i) scanf("%d %d %d %d %d %d", x+i, y+i, z+i, M+i, K+i, C+i);
    ++m; int lim = (1<<m); 
    for(int mask = 0; mask<lim; ++mask) fill(dp[mask], dp[mask]+m, 1e9); //initailly fill with inf
    dp[1][0] = 0;
    for(int mask = 0; mask<lim; ++mask){
        for(int v = 0; v<m; ++v){
            if(mask>>v&1){
                int pmask = mask ^ (1<<v); //remove v from mask 
                for(int u = 0; u<m; ++u){
                    if(pmask>>u&1){
                        if(dp[pmask][u] < 1e9){
                            int w = sq(x[u]-x[v]) + sq(y[u]-y[v]) + sq(z[u]-z[v]); //calculating distance travelled
                            dp[mask][v] = min(dp[mask][v], dp[pmask][u] + w); 
                        }
                    }
                }
            }
        }
    }
    int mn = 1e9; 
    for(int mask = 0; mask<lim; ++mask){
        int eq[3] = {0, 0, 0};
        for(int j = 0; j<m; ++j){
            if(mask>>j&1){eq[0] += M[j]; eq[1] += K[j]; eq[2] += C[j];}
        }
        if(min({eq[0], eq[1], eq[2]}) >= n) mn = min(mn, *min_element(dp[mask], dp[mask]+m)); 
        //find if we visited the shops presented in mask, can we make at least n computers? 
    }
    printf("%d", mn);
}
