//toi20_lover
//dynamic programming + prefix sum
//O(N^2)
#include <stdio.h>
#define N 10001
int dp[N], qs[2][N];
signed main(){
	int n, V, W; scanf("%d %d %d", &n, &V, &W);
	for(int i = 1, x; i<=n; dp[i++] = n+1) scanf("%d", &x), qs[x&1][i] = x;
	for(int j = dp[0] = 0; j<2; ++j) for(int i = 1; i<=n; ++i) qs[j][i] += qs[j][i-1]; 
	for(int i = 2; i<=n; i+=2){
		for(int j = i-1, m; j>=1; j-=2){
			m = (i+j)>>1;
			if(qs[1][m] <= V + qs[1][j-1] && qs[0][i] <= W + qs[0][m] && dp[j-1] + 1 < dp[i]){
				dp[i] = dp[j-1] + 1;
			}
		}
	}
	printf("%d", (dp[n]) > n ? -1 : dp[n]);
}
