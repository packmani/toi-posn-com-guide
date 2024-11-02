#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long int INF = 1e18;
const int MOD = 1e9+7;
const int N = 1e6+10;
long long int dp[5][N];
pair<int,long long int> price[5];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    price[1] = {1,500}; price[2] = {2,800}; price[3] = {5,1500}; price[4] = {15,3000};
    for(int i=1;i<=4;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = INF;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=n;j++){
            if(i != 1){
                dp[i][j] = dp[i-1][j];
            }
            if(j - price[i].first > 0){
                dp[i][j] = min(dp[i][j-price[i].first] + price[i].second, dp[i][j]);
            }
            else{
                dp[i][j] = min(price[i].second, dp[i][j]);
            }
        }
    }
    cout << dp[4][n] << endl;
}
