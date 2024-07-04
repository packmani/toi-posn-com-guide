//TOI19-energy
#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
ll dp[10][300][300], qs[300];
ll sum(int l, int r){return (l)? qs[r] - qs[l-1] : qs[r];}
signed main(){
	int n, k, d; scanf("%d %d %d", &n, &k, &d);
	for(int i = 0; i<n; ++i){scanf("%lld", qs+i); if(i) qs[i] += qs[i-1];}
	for(int i = 0; i<n; ++i) for(int j = i; j<n; ++j) dp[k][i][j] = 1;
	for(int lv = k-1; lv>=1; --lv){
		for(int i = n-1; i>=0; --i){
			for(int j = i+1; j<n; ++j){
				for(int x = i; x<j; ++x){
					if(abs(sum(i, x) - sum(x+1, j)) <= d){
						dp[lv][i][j] = (dp[lv][i][j] + (dp[lv+1][i][x] * dp[lv+1][x+1][j]) % mod) % mod;
					}
				}
			}
		}
	}
	printf("%lld", dp[1][0][n-1]);
}
