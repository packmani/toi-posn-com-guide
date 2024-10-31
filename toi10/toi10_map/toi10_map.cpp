//toi10_map
//bfs transversal
#include <cstdio>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
vector<pair<int,int>> g[40005]; // {direction, no.}
tuple<int,int,int> coord[40005]; 
bool vis[40005];
signed main(){
    int m, n, sz = 0; scanf("%d %d", &m, &n);
    for(int i = 0, u, v; i<m*n-1; ++i){
        char c; scanf("%d %c %d", &u, &c, &v);
        if(c == 'U'){ g[u].emplace_back(0, v); g[v].emplace_back(1, u);}
        else if(c == 'L'){ g[u].emplace_back(2, v); g[v].emplace_back(3, u);}
    }
    queue<tuple<int,int,int>> q;
    q.emplace(0, 0, 0); vis[0] = true; //start with random positon (0, 0)
    while(!q.empty()){
        int no, i, j; tie(no, i, j) = q.front(); q.pop();
        coord[sz++] = make_tuple(i, j, no);
        for(pair<int,int> it: g[no]){
            if(vis[it.second]) continue;
            int dir = it.first, ni = i, nj = j;
            if(!dir) ++ni;
            else if(dir == 1) --ni;
            else if(dir == 2) ++nj;
            else if(dir == 3) --nj;
            q.emplace(it.second, ni, nj); vis[it.second] = true;
        }
    }
    sort(coord, coord+sz); //sort by row and then by column
    for(int i = 0; i<sz; ++i){
        if(i && get<0>(coord[i-1]) != get<0>(coord[i])) puts(""); //change row?
        printf("%d ", get<2>(coord[i]));
    }
}
