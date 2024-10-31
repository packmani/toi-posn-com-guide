//toi13_robot
//muti-source bfs to find the shortest path on unweighted graph
#include <cstdio>
#include <queue>
#include <cstring>
int m, n, D[2000][2000];
char s[2000][2001];
const int px[4] = {-1, 0, 1, 0};
const int py[4] = {0, -1, 0, 1}; // four directions
bool V(int i, int j){return i>=0 && j>=0 && i<m && j<n;} //check if inside grid?
signed main(){
    scanf("%d %d", &m, &n);
    memset(D, -1, sizeof(D));
    std::queue<std::pair<int,int>> q;
    for(int i = 0; i<m; ++i){
        scanf("%s", s[i]);
        for(int j = 0; j<n; ++j) if(s[i][j] == 'X'){D[i][j] = 0; q.emplace(i, j);}
    }
    while(!q.empty()){
        int i = q.front().first, j = q.front().second; q.pop();
        for(int w = 0; w<4; ++w){
            int x = i + px[w], y = j + py[w];
            if(V(x, y) && s[x][y] != 'W' && D[x][y] == -1){D[x][y] = D[i][j] + 1; q.emplace(x, y);}
        }
    }
    int ans = 0, cnt = 0;
    for(int i = 0; i<m; ++i) for(int j = 0; j<n; ++j) if(s[i][j] == 'A' && D[i][j] != -1){++cnt; ans += D[i][j] + D[i][j]; // go to target and come back}
    printf("%d %d", cnt, ans);
}
