//toi19_phitsanulok
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int,int>> g[524288]; 
long long D[524288]; //shortest path from (00..0)2
bool vis[524288];
signed main(){
	int n, s; scanf("%d %d", &n, &s);
	vector<int> P;
	for(int i = 0, w; i<n; ++i){
		scanf("%d", &w);
		int poison = 0, antidote = 0;
		for(int j = 0, p; j<s; ++j){
			scanf("%d", &p);
			if(p < 0) poison += (1<<j); 
			else if(p > 0) antidote += (1<<j);
		}
		g[poison].emplace_back(w, antidote);
		P.push_back(poison);
	}
	using pli = pair<long long,int>;
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	fill(D, D+(1<<s), 1e18);
	pq.emplace(D[0] = 0, 0);
	while(!pq.empty()){ //dijkstra
		int u = pq.top().second; pq.pop();
		if(vis[u]) continue; vis[u] = true;
		for(pair<int,int> it: g[u]){
			int w = it.first, v = it.second;
			if(D[u] < 1e18 && D[u] + w < D[v]) pq.emplace(D[v] = D[u] + w, v);
		}
		for(int j = 0; j<s; ++j){ //subset
			if((u>>j&1) && D[u] < D[u ^ (1<<j)]) pq.emplace(D[u ^ (1<<j)] = D[u], u ^ (1<<j));
		}
	}
	long long Ans = LLONG_MIN;
	for(int poison : P) if(D[poison] < 1e18) Ans = max(Ans, D[poison]);
	printf("%lld", Ans);
}
