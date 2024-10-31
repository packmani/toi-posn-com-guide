//toi14_blockchain
//compare graph using vector of pair {u, v}
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
std::map<std::vector<std::pair<int,int>>, int> mp;

std::vector<std::pair<int,int>> cp(){
    int e, u, v; scanf("%d", &e); --e;
    std::vector<std::pair<int,int>> vec;
    while(e--){
        scanf("%d %d", &u, &v);
        vec.emplace_back(std::min(u, v), std::max(u, v));
    }
    std::sort(vec.begin(), vec.end());
    return vec;
}
signed main(){
    int n, m; scanf("%d %d", &n, &m);
    while(n--) ++mp[cp()];
    while(m--) printf("%d\n", mp[cp()]);
}
