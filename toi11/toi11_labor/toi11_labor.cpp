#include<bits/stdc++.h>
using namespace std;
#define int long long int
int arr[1000005];
int n,m;
bool check(int mid)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=mid/arr[i];
	return (sum>=m);
}
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int l=1;
	int r=1000000*m;
	int mid=l+(r-l)/2;
	int ans=LLONG_MAX;
	while(l<=r)
	{
		if(check(mid))
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
		mid=l+(r-l)/2;
	}
	cout << mid;
}
