#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int SZ = 1000005;
const int mod = 1e9 + 7;
int n;
int arr[SZ];
vector<int> adj[SZ];
int fact[SZ];
int combi[SZ];

void genfactorial(int n)
{
	//compute factorial up to n!, and fill array values with 1
	fact[0]=1;
	for(int i=1;i<=n;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
		combi[i]=1;
	}
	return;
}

void dfs(int node, int par)
{
	/*
	dfs from root and compute for each subtree.
	number of ways to traverse from root
	= number of ways to traverse each subtree * number of ways to order each subtree
	= subtree1 * subtree2 * .... * subtree(n) * n!
	*/
	int cnt=0;
	for(auto to:adj[node])
	{
		if(to==par) continue;
		dfs(to,node);
		combi[node]*=combi[to];
		combi[node]%=mod;
		cnt++;
	}
	combi[node]*=fact[cnt];
	combi[node]%=mod;
	return;
}
int32_t main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	genfactorial(n);
	for(int i=0;i<2*n-1;i++)
	{
		cin >> arr[i];
		if(i>0) adj[arr[i]].push_back(arr[i-1]);
	}
	dfs(arr[0],arr[0]);
	cout << combi[arr[0]];
}
