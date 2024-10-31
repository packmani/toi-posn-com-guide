//toi12_pipe
//MST using Prim's algo O(N^2)
//marked nodes (already in MST) is represented as prefix till i (i is the current node try to be expanded from)
//so unmarked nodes (not in MST) is in [i+1, n) 
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int D[15001], x[15001], y[15001]; 
signed main(){
    int n, k; scanf("%d %d", &n, &k);
    for(int i = 0; i<n; ++i){scanf("%d %d", x+i, y+i); D[i] = 1e9;}
    long long MST = D[0] = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<n; ++i){
        pair<int,int> mn = make_pair(1e9, -1);
        for(int j = i+1; j<n; ++j){
            int w = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            mn = min(mn, make_pair(D[j] = min(D[j], w), j));
        }
        if(mn.first == 1e9) break;
        int u = mn.second;
        swap(D[i+1], D[u]); swap(x[i+1], x[u]); swap(y[i+1], y[u]); //we swap to maintain the marked nodes as prefix property
        MST += mn.first; pq.push(mn.first); while(pq.size() >= k) pq.pop(); //maintain k-1 largest 
    }
    while(!pq.empty()){MST -= pq.top(); pq.pop();} //minimum k components -> remove largest k-1 edges 
    printf("%lld\n", MST);
}
