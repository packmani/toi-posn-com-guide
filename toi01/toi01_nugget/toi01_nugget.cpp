#include<bits/stdc++.h>
using namespace std;
#define int long long int
int dp[100] , n;
int32_t main()
{
	cin >> n;
	if(n<6)
  {
    cout << "no";
    return 0;
  }
	dp[6]=dp[9]=dp[12]=dp[15]=dp[18]=dp[20]=1 ; //basecase จน.นักเกต 0 ชิ้น สร้างได้เสมอ
	for(int i=20 ; i<=n ; i++)
    dp[i]|=dp[i-6] , dp[i]|=dp[i-9] , dp[i]|= dp[i-20];
	for(int i=6 ; i<=n ; i++)
    if(dp[i])cout << i << '\n';
}
