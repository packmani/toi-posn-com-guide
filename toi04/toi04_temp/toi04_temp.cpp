//toi4_temp
//BFS
#include <cstdio>
#include <queue>
const short px[4] = {-1, 0, 1, 0}, py[4] = {0, 1, 0, -1};
short a[20][20], v[20][20], mx = -6;
signed main(){
    short n, sc, sr; scanf("%hd %hd %hd", &n, &sc, &sr); --sr; --sc;
    for(short i = 0; i<n; ++i){
        for(short j = 0; j<n; ++j){
            scanf("%hd", &a[i][j]);
            if(a[i][j] == 100) a[i][j] = -6; //make it impossible to pass
        }
    }
    std::queue<std::pair<short,short>> q; q.emplace(sr, sc); v[sr][sc] = 1;
    while(!q.empty()){
        short i = q.front().first, j = q.front().second; q.pop();
        if(a[i][j] > mx) mx = a[i][j]; //keep maximum
        for(short w = 0; w<4; ++w){ //walk in 4 directions
            short x = i + px[w], y = j + py[w];
            if(~x && ~y && x<n && y<n && !v[x][y] && a[x][y] > a[i][j]) q.emplace(x, y), v[x][y] = 1; //on grid and strictly increasing
        }  
    }
    printf("%hd", mx);
}
