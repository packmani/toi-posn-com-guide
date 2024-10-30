//toi18_sausage
#include <cstdio>
#include <algorithm>
using namespace std;
int D[5000];
long long dp[5000][5000], DP[5000];
signed main(){
    int n; scanf("%d", &n);
    for(int i = 0; i<n; ++i){scanf("%d", D+i); fill(dp[i], dp[i]+n, -1e18); dp[i][i] = D[i];}
    for(int i = n-1; i>=0; --i){
        for(int j = i+1; j<n; ++j){
            if(i+1 < n) dp[i][j] = max(dp[i][j], dp[i+1][j] + D[i] + abs(D[i] - D[j]));
            if(j) dp[i][j] = max(dp[i][j], dp[i][j-1] + D[j] + abs(D[i] - D[j]));
        }
    }
    for(int i = 0; i<n; ++i) DP[i] = dp[0][i];
    for(int i = 1; i<n; ++i){
        for(int j = 0; j<i; ++j){
            DP[i] = max(DP[i], DP[j] + dp[j+1][i]);
        }
    }
    printf("%lld", DP[n-1]);
}
