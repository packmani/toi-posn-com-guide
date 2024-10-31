//toi11_candle
//count number of connected components using bfs
#include <cstdio>
#include <queue>
int m, n; 
bool vis[2000][2000];
char s[2000][2001];
bool V(int i, int j){return i>=0 && j>=0 && i<m && j<n;} //check if inside grid?
signed main(){
    scanf("%d %d", &m, &n);
    for(int i = 0; i<m; ++i) scanf("%s", s[i]);
    std::queue<std::pair<int,int>> q;
    int cmp = 0;
    for(int i = 0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            if(!vis[i][j] && s[i][j] == '1')    { //flood fill
                q.emplace(i, j); vis[i][j] = true; ++cmp;
                while(!q.empty()){            
                    int x = q.front().first, y = q.front().second; q.pop();
                    for(int w1 = -1; w1<=1; ++w1){
                        for(int w2 = -1; w2<=1; ++w2){
                            int nx = x + w1, ny = y + w2;
                            if(V(nx, ny) && s[nx][ny] == '1' && !vis[nx][ny]){
                                q.emplace(nx, ny); vis[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d", cmp);
}
