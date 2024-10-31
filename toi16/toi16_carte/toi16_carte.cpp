#include<bits/stdc++.h>
using namespace std;
#define int long long int
int q,k,n;
int arr[405];
int cnt[405][405];
int dp[405][405];
int ans;
int32_t main()
{
    cin >> q >> k;
    while(q--)
    {
        cin >> n;
        int j=0;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            //base case
            dp[i][i] = cnt[i][i] = 1;
        }
        for(int sz=2;sz<=n;sz++)
        {
            for(int i=0;i<n-sz+1;i++)
            {
                int j = i+sz-1;
                dp[i][j] = INT_MAX;
                cnt[i][j] = INT_MAX;
                //case 1 -> can be pulled at the same time
                if(arr[i]==arr[j])
                {
                    //you have pulls left
                    if(cnt[i][j-1]<k)
                    {
                        dp[i][j] = dp[i][j-1];
                        cnt[i][j] = cnt[i][j-1]+1;
                    }
                    //already used k pulls -> reset pulls
                    else
                    {
                        dp[i][j] = dp[i][j-1]+1;
                        cnt[i][j] = 1;
                    }
                }
                //better to split into substrings
                for(int k=i;k<j;k++)
                {
                    //similar to dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
                    //but just doing that is incorrect, because of k values
                    
                    //better value 
                    if(dp[i][k]+dp[k+1][j]<dp[i][j])
                    {
                        dp[i][j] = dp[i][k]+dp[k+1][j];
                        cnt[i][j] = cnt[i][k];
                    }
                    //same value -> try to find better count
                    else if(dp[i][j]==dp[i][k]+dp[k+1][j])
                    {
                        cnt[i][j] = min(cnt[i][j],cnt[i][k]);
                    }
                }
            }
        }
        ans = max(ans,dp[0][n-1]);
    }
    cout << ans;
}
