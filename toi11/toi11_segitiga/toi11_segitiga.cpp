//toi11_segitiga
//dp mcm style
#include <cstdio>
#include <cstring>
bool dp[3][255][255];  
char s[256];
const int op[3][3] = {{2, 1, 0}, {2, 1, 1}, {1, 2, 1}};
signed main(){
    for(int tt = 0, n; tt<20; ++tt){
        scanf("%d %s", &n, s);
        for(int i = 0; i<n; ++i) dp[s[i]-'0'][i][i] = true;
        for(int i = n-1; i>=0; --i){
            for(int j = i+1; j<n; ++j){
                for(int k = i; k<j; ++k){
                    for(int w1 = 0; w1<3; ++w1){
                        for(int w2 = 0; w2<3; ++w2){
                            dp[op[w1][w2]][i][j] |= dp[w1][i][k] & dp[w2][k+1][j];
                        }
                    }
                }
            }
        }
        if(dp[0][0][n-1]) puts("yes");
        else puts("no");
        for(int i = 0; i<n; ++i) for(int j = i; j<n; ++j) dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = false;
    }
}
