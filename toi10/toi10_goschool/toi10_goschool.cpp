//toi10_goschool
//count no of ways using dynamic programming
#include <cstdio>
long long dp[50][50];
signed main(){
    int m, n, o, x, y; scanf("%d %d %d", &m, &n, &o);
    while(o--){
        scanf("%d %d", &x, &y); dp[--x][--y] = -1;
    }
    dp[0][0] = 1;
    for(int i = 0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            if(dp[i][j] == -1){dp[i][j] = 0; continue;} //dog 
            if(i) dp[i][j] += dp[i-1][j]; //walk up
            if(j) dp[i][j] += dp[i][j-1]; //walk right
        }
    }
    printf("%lld", dp[m-1][n-1]); 
}
