#include <stdio.h>
#include <string.h>
#define N 1001
#define dN 2001
int dp[N][N], F[N*N], S[N*N], m, n, k, sz;
char a[N], b[N], s[dN];
signed main(){
	scanf("%s %s %d", a, b, &k);
	m = strlen(a); n = strlen(b);	
	dp[0][0] = 1;
	while(k--){
		scanf("%s", s);
		for(int j = 1; j<=n; ++j) if(dp[0][j-1] && (b[j-1] == s[j-1])) dp[F[sz] = 0][S[sz] = j] = 1, ++sz;
		for(int i = 1; i<=m; ++i){
			if(dp[i-1][0] && (a[i-1] == s[i-1])) dp[F[sz] = i][S[sz] = 0] = 1, ++sz;
			for(int j = 1; j<=n; ++j){
				if((dp[i-1][j] && (a[i-1] == s[i+j-1])) || (dp[i][j-1] && (b[j-1] == s[i+j-1]))){
					dp[F[sz] = i][S[sz] = j] = 1; ++sz;
				}
			}
		}
		(dp[m][n]) ? puts("Yes") : puts("No");
		for(int i = 0; i<sz; ++i) dp[F[i]][S[i]] = 0;
	}
}
