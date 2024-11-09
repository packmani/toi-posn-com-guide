#include<bits/stdc++.h>
using namespace std;
int n;
string str;
bool dp[255][255][3]; //dp[i][j][k]is it possible to make k from range i to including j 
int res;
int operate(int num1, int num2)
{
	if(num1==0 and num2==0) return 2;
	else if(num1==0 and num2==1) return 1;
	else if(num1==0 and num2==2) return 0;
	else if(num1==1 and num2==0) return 2;
	else if(num1==1 and num2==1) return 1;
	else if(num1==1 and num2==2) return 1;
	else if(num1==2 and num2==0) return 1;
	else if(num1==2 and num2==1) return 2;
	else if(num1==2 and num2==2) return 1;
	return -1;
}
int32_t main()
{
	cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
	for(int q=0;q<20;q++)
	{
		cin >> n >> str;
		memset(dp,0,sizeof(dp));

		for(int i=0;i<n;i++)
			dp[i][i][str[i]-'0']=1;

		for(int j=1;j<n;j++) //range size
		{
			for(int i=0;i<n-j;i++) //starting point
			{
				for(int k=i;k<i+j;k++) //inter
				{
					if(dp[i][k][0] and dp[k+1][i+j][0]) dp[i][i+j][2]=1;
					if(dp[i][k][0] and dp[k+1][i+j][1]) dp[i][i+j][1]=1;
					if(dp[i][k][0] and dp[k+1][i+j][2]) dp[i][i+j][0]=1;
					if(dp[i][k][1] and dp[k+1][i+j][0]) dp[i][i+j][2]=1;
					if(dp[i][k][1] and dp[k+1][i+j][1]) dp[i][i+j][1]=1;
					if(dp[i][k][1] and dp[k+1][i+j][2]) dp[i][i+j][1]=1;
					if(dp[i][k][2] and dp[k+1][i+j][0]) dp[i][i+j][1]=1;
					if(dp[i][k][2] and dp[k+1][i+j][1]) dp[i][i+j][2]=1;
					if(dp[i][k][2] and dp[k+1][i+j][2]) dp[i][i+j][1]=1;

				}
			}
		}
		if(dp[0][n-1][0]==1) cout << "yes" <<'\n';
		else cout << "no" << '\n';
	}
}
