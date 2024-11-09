#include <cstdio>
#include <algorithm>
const int N = 2000;
int m, n, k, h[N][N], QS[N][N], qs1[N][N], qs2[N][N], mx = -2e9;
signed main(){
	scanf("%d %d %d", &m, &n, &k);
	for(int i = 0; i<m; ++i){
		for(int j = 0; j<n; ++j){
			scanf("%d", &h[i][j]);
			QS[i][j] = (i && j) ? QS[i-1][j-1] + h[i][j] : h[i][j]; 
			qs1[i][j] = (i) ? qs1[i-1][j] + QS[i][j] : QS[i][j];
			qs2[i][j] = (j) ? qs2[i][j-1] + QS[i][j] : QS[i][j];
			if(i >= k-1 && j >= k-1){
				mx = std::max(mx, qs2[i][j] - ((j >= k) ? qs2[i][j-k] : 0) - ((i && j >= k) ? qs1[i-1][j-k] : 0) + ((i >= k+1 && j >= k) ? qs1[i-k-1][j-k] : 0));
			}
		}
	}
	for(int i = 0; i<m; ++i){
		for(int j = n-1; ~j; --j) QS[i][j] = (i && j < n-1) ? QS[i-1][j+1] + h[i][j] : h[i][j];
		for(int j = 0; j<n; ++j){
			qs1[i][j] = (i) ? qs1[i-1][j] + QS[i][j] : QS[i][j];
			qs2[i][j] = (j) ? qs2[i][j-1] + QS[i][j] : QS[i][j];
			if(i >= k-1 && j >= k-1){
				mx = std::max(mx, qs2[i][j] - ((j >= k) ? qs2[i][j-k] : 0) - ((i && j < n-1) ? qs1[i-1][j+1] : 0) + ((i >= k+1 && j < n-1) ? qs1[i-k-1][j+1] : 0));  
			}
		}
	}
	printf("%d", mx);
}
