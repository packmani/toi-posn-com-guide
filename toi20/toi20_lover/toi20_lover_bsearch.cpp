//TOI20-Lover-Binary Search
//31/05/24
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e4 + 5;
int qs[2][N];
int sum(int j, int l, int r){return qs[j][r] - qs[j][l-1];}
int dp[N], lg[2][N];
signed main(){
    int n, lim[2]; scanf("%d %d %d", &n, lim+1, lim+0);
    for(int i = 1, x; i<=n; ++i){
        scanf("%d", &x); qs[x&1][i] = x;
        qs[0][i] += qs[0][i-1]; qs[1][i] += qs[1][i-1];
    }
    for(int i = 1; i<=n; ++i){
        for(int j = 0; j<2; ++j){
            int low = 1, high = i; lg[j][i] = n + 1;
            while(low <= high){
                int mid = low + ((high-low)>>1);
                if(sum(j, mid, i) <= lim[j]){
                    high = mid-1; lg[j][i] = mid;
                }else{
                    low = mid+1;
                }
            }
        }
    }
    fill(dp, dp+n+1, 1e9);
    dp[0] = 0;
    for(int i = 1; i<=n; ++i){
        for(int j = lg[0][i] - 1; j<i; ++j){
            if(j > 0 && lg[1][j] > 0 && j - lg[1][j] + 1 >= i - j){
                dp[i] = min(dp[i], dp[j-(i-j)] + 1);
            }
        }
    }
    printf("%d", (dp[n] >= 1e9)? -1 : dp[n]);
}
