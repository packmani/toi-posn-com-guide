//toi8_schedule
//dynamic programming
#include <cstdio>
#include <algorithm>
#define mp make_pair
#define F first
#define S second
using namespace std;
pair<int,int> dp[1001][1001]; // {day, time used} 
int J[1001], K[1001], m, n;
signed main(){
    scanf("%d %d", &m, &n);
    for(int i = 1; i<=n; ++i) scanf("%d", J+i);
    for(int i = 1; i<=n; ++i) scanf("%d", K+i);
    for(int i = 0; i<=n; ++i) fill(dp[i], dp[i]+n+1, mp(1e9, 1e9));
    dp[0][0] = mp(1, 0); //base case
    for(int i = 0; i<=n; ++i){
        for(int j = 0; j<=n; ++j){
            if(i) dp[i][j] = min(dp[i][j], mp(dp[i-1][j].F + (dp[i-1][j].S + J[i] > m), (dp[i-1][j].S + J[i] <= m)/*(0/1)*/ * dp[i-1][j].S + J[i]));
            //if prev time used (dp[i-1][j].S) + J[i] > M then we need to do on new day
            if(j) dp[i][j] = min(dp[i][j], mp(dp[i][j-1].F + (dp[i][j-1].S + K[j] > m), (dp[i][j-1].S + K[j] <= m) * dp[i][j-1].S + K[j]));
        }
    }
    printf("%d\n%d", dp[n][n].F, dp[n][n].S);
}
