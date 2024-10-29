#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int SZ = 1e5+5;
int x[SZ],s[SZ],y[SZ],t[SZ];
int n,m,q,a,b,k;
int idx1,idx2,ans,l,r,mid,sum;
int32_t main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
	for(int i=0;i<n;i++)
	{
		cin >> x[i];//values
	}
	for(int i=0;i<n;i++)
	{
		cin >> s[i];//slots
		if(i>0) s[i]+=s[i-1];
	}
	for(int i=0;i<m;i++)
	{
		cin >> y[i];//values
	}
	for(int i=0;i<m;i++)
	{
		cin >> t[i];//slots
		if(i>0) t[i]+=t[i-1];
	}
	while(q--)
	{
		//bsearch on values... get pref freq
		cin >> a >> b >> k;
		l=-1e9; r=1e9; mid = l+(r-l)/2;
		while(l<=r)
		{
			idx1 = upper_bound(x,x+n,mid) - x - 1; //check first element less than mid x
			idx2 = upper_bound(y,y+m,(mid-b)/a) - y - 1; //check first element less than mid in y(transformed)
			sum=0;
			if(idx1>=0) sum+=s[idx1];
			if(idx2>=0) sum+=t[idx2];
			if(sum<k) l=mid+1;
			else 
			{
				r=mid-1;
				ans=mid;
			}
			mid = l+(r-l)/2;
		}
		cout << ans << '\n';
		
	}
}
