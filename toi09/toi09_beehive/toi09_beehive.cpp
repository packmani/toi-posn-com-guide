//toi9_beehive
//dynamic programming
#include <cstdio>
int dp[2][1001], ways[2][1001]; //keep only two rows to save memory (because we only use values from previous row)

signed main(){
    int m, n, x, tmp, mx = 0, cnt = 0; scanf("%d %d", &m, &n);
    for(int j = 0; j<n; ++j){scanf("%d", &dp[0][j]); ways[0][j] = 1;} //base case
    for(int i = 1; i<m; ++i){
        for(int j = 0; j<n; ++j){
            scanf("%d", &x); int ci = i&1, pi = ci^1, pj = (i&1)? j+1 : j-1;
            dp[ci][j] = dp[pi][j] + x; ways[ci][j] = ways[pi][j];
            tmp = dp[pi][pj] + x;
            if(tmp > dp[ci][j]){dp[ci][j] = tmp; ways[ci][j] = ways[pi][pj];}
            else if(tmp == dp[ci][j]) ways[ci][j] += ways[pi][pj];
        }
    }
    m = (--m)&1; 
    for(int j = 0; j<n; ++j){
        if(dp[m][j] > mx){mx = dp[m][j]; cnt = ways[m][j];}
        else if(dp[m][j] == mx) cnt += ways[m][j];
    } 
    printf("%d %d", mx, cnt);
}
