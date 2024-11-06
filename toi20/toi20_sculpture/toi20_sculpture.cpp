#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int SZ = 20005;
int n;
int weight[SZ],limit[SZ];
int ans;
int minweight[SZ];
int maxcap[SZ];
int bestsz[SZ];
int bestsz2[SZ];
vector<int> ansvec;
int32_t main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> weight[i] >> limit[i];
		//fill dp table
		minweight[i+1]=LLONG_MAX; 
		maxcap[i+1]=LLONG_MIN;
	}
	//fill dp table
	minweight[0]=0;
	maxcap[0]=INT_MAX;
	//first pass, find best height ending at every i 
	for(int i=0;i<n;i++)
	{
		for(int k=i+1;k>=1;k--)
		{
			if(limit[i]>=minweight[k-1]) 
			{
				minweight[k]=min(minweight[k-1]+weight[i],minweight[k]);
				bestsz[i]=max(bestsz[i],k);
			}
		}
	}
	//second pass, find best height with n-i stones (doesnt have to start at the n-ith stone)
	for(int i=n-1;i>=0;i--)
	{
		for(int k=n-i;k>=1;k--)
		{
			if(maxcap[k-1]>=weight[i]) maxcap[k] = max(maxcap[k],min(maxcap[k-1]-weight[i],limit[i]));
			if(maxcap[k]!=LLONG_MIN) bestsz2[i]=max(bestsz2[i],k);
		}
	}
	//third pass, check every stone as the ending and put the weight helper on
	//and combine height from before helper and after helper
	for(int i=0;i<n-1;i++)
	{
		if(bestsz[i]+bestsz2[i+1]>ans)
		{
			ans = bestsz[i] + bestsz2[i+1];
			ansvec.clear();
			ansvec.push_back(i+1);
		}
		else if(bestsz[i]+bestsz2[i+1]==ans)
		{
			ansvec.push_back(i+1);
		}
	}
	cout << ans <<'\n';
	for(int i=0;i<ansvec.size();i++)
		cout << ansvec[i] << ' ' ;
}
