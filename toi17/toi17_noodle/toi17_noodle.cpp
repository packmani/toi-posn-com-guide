#include <bits/stdc++.h>
#define tp top()
#define sz size()
#define ll long long
using namespace std;
ll n,m,k;
ll e[100005];

bool check(ll x) {
	ll sum=0,count=0;
	priority_queue <ll, vector<ll>, greater<ll> > pq;
	for(int i=0;i<n;i++) {
		if(pq.sz < k) {
			pq.push(e[i]);
			sum+=e[i];
		} else if (pq.tp < e[i]) {
			sum-=pq.tp;
			pq.pop();
			sum+=e[i];
			pq.push(e[i]);
		}
		
		if(sum>=x && pq.sz==k) {
			count++;
			sum = 0;
			while(!pq.empty())
				pq.pop();
			if(count==m)
				return true;
		}
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
		cin >> e[i];
	ll l=1,r=LLONG_MAX;
	while(l!=r) {
		ll mid = (l+r+1)/2;
		if(check(mid))
			l = mid;
		else
			r = mid-1;
	}
	cout << l;
	return 0;
}
