//toi6_tree
//compare two tree
//check if list of edge is the same?
#include <cstdio>
#include <vector>
#include <algorithm>
std::vector<std::pair<int,int>> e[2];
signed main(){
    int tc = 5; 
    while(tc--){
        int n; scanf("%d", &n); e[0].resize(n-1); e[1].resize(n-1);
        for(int j = 0; j<2; ++j){
            for(int i = 0, u, v; i<n-1; ++i){scanf("%d %d", &u, &v); e[j][i] = std::make_pair(std::min(u, v), std::max(u, v));}
        }
        for(int j = 0; j<2; ++j) std::sort(e[j].begin(), e[j].end()); //sort to compare
        if(e[0] == e[1]) printf("Y");
        else printf("N");
    }
}
