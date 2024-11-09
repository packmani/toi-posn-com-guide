#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n,q;
int num;
int s,money;
int points[500005];
vector<int> price;
int32_t main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> q;
	price.push_back(0);
	for(int i=1;i<=n;i++)
	{
		cin >> num;
		int temp=0;
		if(num<=0) temp = abs(num);
		else points[i]=num;
		points[i]+=points[i-1];
		price.push_back(price[i-1]+temp);
	}
	price.push_back(LLONG_MAX);
	points[n+1]=points[n];
	for(int i=0;i<q;i++)
	{
		cin >> s >> money;
		int idx = lower_bound(price.begin()+s,price.end(),money+price[s])-price.begin();
		cout << points[idx] - points[s] << '\n';
	}
}
