//toi11_candle
//DSU
#include <cstdio>
#include <algorithm>
#define C sz
int m, n, p[4000000], sz[4000000]; 
char s[2000][2001]; 
bool V(int i, int j){return i>=0 && j>=0 && i<m && j<n;}
int c(int i, int j){return i*n + j;} // 2D -> 1D
int fp(int x){return (x == p[x])? x : p[x] = fp(p[x]);} //path compression
void U(int u, int v){u = fp(u); v = fp(v); if(u == v) return; if(sz[u] < sz[v]) std::swap(u, v); sz[u] += sz[v]; p[v] = u;} //Union two set
signed main(){
    scanf("%d %d", &m, &n);
    for(int i = 0; i<m*n; ++i){sz[i] = 1; p[i] = i;} //initialize
    for(int i = 0; i<m; ++i){
        scanf("%s", s[i]);
        for(int j = 0; j<n; ++j){
            if(s[i][j] == '1'){
                for(int w1 = -1; w1<=1; ++w1){
                    for(int w2 = -1; w2<=1; ++w2){
                        int x = i + w1, y = j + w2;
                        if(V(x, y) && s[x][y] == '1') U(c(i, j), c(x, y));
                    }
                }
            }
        }
    }
    std::fill(C, C+m*n, 0);
    for(int i = 0; i<m; ++i) for(int j = 0; j<n; ++j) C[fp(c(i, j))] = (s[i][j] == '1'); //mark the root node of each component 
    int cmp = 0;
    for(int i = 0; i<m*n; ++i) cmp += C[i]; //count number of root node
    printf("%d", cmp);
}
