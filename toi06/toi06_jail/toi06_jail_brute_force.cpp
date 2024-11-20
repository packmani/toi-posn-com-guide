//toi6_jail
//brute force simulation
#include <cstdio>
#include <queue>
std::queue<int> q;
signed main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i<=n; ++i) q.push(i);
    while(n--){
        for(int j = 0; j<m-1; ++j) q.push(q.front()), q.pop();
        printf("%d ", q.front()); q.pop();
    }
}
