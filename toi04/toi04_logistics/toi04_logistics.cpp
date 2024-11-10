//toi4_logisitics
//BFS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
std::vector<int> M[270];
std::pair<char,char> cp[270];
std::tuple<char,char,int> E[270];
std::vector<int> g[28];
int Node[28], vis[28], U, V; // X -> 26, Y = 26, [a...z] -> [0...25]
double Ans[270], tot, tmp;
char u, v;
signed main(){
	int n, sz; scanf("%d", &n);
	for(int i = sz = 0, w; i<n; E[i++] = {u, v, w}){
		scanf(" %c %c %d", &u, &v, &w);
		if(u > v) std::swap(u, v);
		cp[sz++] = {u, v};
		if(u == 'X') U = 26;
		else if(u == 'Y') U = 27;
		else U = u - 'a';
		//
		if(v == 'X') V = 26;
		else if(v == 'Y') V = 27;
		else V = v - 'a';
		g[U].push_back(V);
		g[V].push_back(U);
	}
	sort(cp, cp+sz); sz = unique(cp, cp+sz) - cp; //coordinate compress so you don't have to use map
	for(int i = 0, w; i<n; ++i){
		std::tie(u, v, w) = E[i];
		M[std::lower_bound(cp, cp+sz, std::make_pair(u, v)) - cp].push_back(w); 
	}
	for(int i = 0; i<sz; ++i){
		std::sort(M[i].begin(), M[i].end()); //sort
		n = M[i].size() - 1;
		Ans[i] = (double)(M[i][(n>>1) + (n&1)] + M[i][n>>1]) / 2.0; //median
	}
	std::queue<int> q;
	q.emplace(26); vis[26] = 1; //26 = X
	for(n = 0; !q.empty(); ){
		Node[n++] = U = q.front(); q.pop(); 
		for(int V: g[U]) if(!vis[V]) vis[V] = 1, q.push(V);
	}
	if(!vis[27]){ puts("broken"); return 0;} //cannot go from X to Y
	for(int i = 1; i<n; ++i){ //Node by bfs order
		U = Node[i-1]; V = Node[i];
		u = (U == 26) ? 'X' : 'Y';
		v = (V == 26) ? 'X' : 'Y';
		if(U < 26) u = U + 'a'; 
		if(V < 26) v = V + 'a';
		tot += (tmp = Ans[std::lower_bound(cp, cp+sz, std::make_pair(std::min(u, v), std::max(u, v))) - cp]); //Ans store median
		printf("%c %c %.1lf\n", u, v, tmp);
	}
	printf("%.1lf", tot);
}
