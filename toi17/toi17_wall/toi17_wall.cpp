#include <cstdio>
#include <queue>
using name1space std;
int m, n;
const int px[4] = {-1, 0, 1, 0};
const int py[4] = {0, -1, 0, 1};
char s[1000][1001];
bool water[1000][1000], vis[1000][1000];
bool V(int i, int j){return i>=0 && j>=0 && i<m && j<n;} //check if inside grid?
queue<pair<int,int>> q;
signed main(){
    scanf("%d %d", &m, &n);
    for(int i = 0; i<m; ++i) scanf("%s", s[i]);
    q.emplace(0, 0); q.emplace(0, n-1); q.emplace(m-1, 0); q.emplace(m-1, n-1);    
    water[0][0] = water[0][n-1] = water[m-1][0] = water[m-1][n-1] = true;
    //flood fill water starting from corners
    while(!q.empty()){
        int i = q.front().first, j = q.front().second; q.pop();
        for(int w = 0; w<4; ++w){
            int x = i + px[w], y = j + py[w];
            if(V(x, y) && s[x][y] == '.' && !water[x][y]){ water[x][y] = true; q.emplace(x, y);}
        }
    }
    //
    int mx = 0;
    for(int a = 0, cnt; a<m; ++a){
        for(int b = 0; b<n; ++b){
            if(s[a][b] == 'X' && !vis[a][b]){
                vis[a][b] = true; q.emplace(a, b); cnt = 0;
                while(!q.empty()){
                    int i = q.front().first, j = q.front().second; q.pop();
                    for(int w = 0; w<4; ++w){int x = i + px[w], y = j + py[w]; if(V(x, y) && water[x][y]) ++cnt;} //check if we can construct a wall (between water cell and 'X')
                    for(int w = 0; w<4; ++w){int x = i + px[w], y = j + py[w]; if(V(x, y) && s[x][y] == 'X' && !vis[x][y]){vis[x][y] = true; q.emplace(x, y);} } //transverse to neighbor
                }
                mx = max(mx, cnt);
            }
        }
    }
    printf("%d", mx);
}
