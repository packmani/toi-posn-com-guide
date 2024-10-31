//toi8_maze 
//bfs from both ends
#include <cstdio>
#include <queue>
const int px[4] = {-1, 0, 1, 0};
const int py[4] = {0, -1, 0, 1}; //four directions
int m, n, rs, cs, re, ce, a[150][150], D[2][150][150]; //D[0] -> minimum distance from (rs cs), D[1] -> from (re, ce)
bool V(int i, int j){return i>=0 && j>=0 && i<m && j<n;} //check if inside grid
std::queue<std::pair<int,int>> q;
//bfs
void bfs(int t){
    //we assume that (rs, cs) and (re, ce) always passable?
    if(!t) {q.emplace(rs, cs); D[t][rs][cs] = 0;}
    else if(t) {q.emplace(re, ce); D[t][re][ce] = 0;}
    while(!q.empty()){
        int i = q.front().first, j = q.front().second; q.pop();
        for(int w = 0; w<4; ++w){
            int x = i + px[w], y = j + py[w];
            if(V(x, y) && a[x][y] && D[t][x][y] == 1e9){D[t][x][y] = D[t][i][j] + 1; q.emplace(x, y);}
        }
    }
}
signed main(){
    scanf("%d %d %d %d %d %d", &m, &n, &rs, &cs, &re, &ce); 
    --rs; --cs; --re; --ce; 
    for(int i = 0; i<m; ++i) for(int j = 0; j<n; ++j){ scanf("%d", &a[i][j]); D[0][i][j] = D[1][i][j] = 1e9;}
    bfs(0); bfs(1);
    int cnt = 0, min_dist = 1e9;
    for(int i = 0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            if(!a[i][j]){
                int mn[2] = {(int)1e9, (int)1e9}; //mn[0] -> from (rs, cs), mn[1] -> from (re, ce)
                for(int w = 0; w<4; ++w){
                    int x = i + px[w], y = j + py[w];
                    if(V(x, y)){mn[0] = std::min(mn[0], D[0][x][y]); mn[1] = std::min(mn[1], D[1][x][y]);}
                }
                if(mn[0] < 1e9 && mn[1] < 1e9){ ++cnt; min_dist = std::min(min_dist, mn[0] + mn[1] + 3/*3 -> (rs, cs), (re, ce), (i,j)*/); } //if (i,j) could be bombed
            }
        }
    }
    printf("%d\n%d", cnt, min_dist);
}
