#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, sz[3005], p[3005];
int fp(int x){if(x == p[x]) return x; return p[x] = fp(p[x]);}
void U(int u, int v){
	u = fp(u); v = fp(v); if(u == v) return; if(sz[u] < sz[v]) swap(u, v); sz[u] += sz[v]; p[v] = u;
}
vector<tuple<int,int,int>> E;
pair<int,int> A[(int)(1e6 + 3005)];
vector<int> cp;
const ll inf = 1e15;
ll bit[(int)(1e6 + 3005)];
void upd(int i, ll val){
	for(; i<=m; i+=i&-i) bit[i] = min(bit[i], val);
}
ll qry(int i){
	ll res = inf; for(; i; i-=i&-i) res = min(res, bit[i]); return res;
}
signed main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; ++i) p[i] = i, sz[i] = 1;
	for(int i = 0, u, v, w, t; i<m; ++i){
		scanf("%d %d %d %d", &u, &v, &w, &t);
		if(t) U(u, v);
		else E.emplace_back(w, u, v);
	}
	sort(E.begin(), E.end());
	vector<int> T;
	for(tuple<int,int,int>& it: E){
		int w, u, v; tie(w, u, v) = it;
		if(fp(u) != fp(v)){
			U(u, v); 
			T.push_back(w);
			cp.push_back(w);
		}
	}
	int k; scanf("%d", &k);
	for(int i = 0, d, c; i<k; ++i){
		scanf("%d %d", &d, &c);
		A[i] = make_pair(d, c);	
		cp.push_back(d);
	}
	sort(cp.begin(), cp.end()); cp.resize(unique(cp.begin(), cp.end()) - cp.begin()); m = cp.size();
	fill(bit, bit+m+1, inf);
	for(int i = 0; i<k; ++i){
		int d = A[i].first, c = A[i].second;
		int j = upper_bound(cp.begin(), cp.end(), d) - cp.begin();
		upd(m-j+1, c);
	}
	ll Ans = 0;
	for(int x: T){
		int j = upper_bound(cp.begin(), cp.end(), x) - cp.begin();
		Ans += qry(m-j+1);
	}
	printf("%lld", Ans);
}
