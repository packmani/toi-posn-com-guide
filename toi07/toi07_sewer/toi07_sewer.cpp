//toi7_sewer
//bfs
#include <cstdio>
#include <queue>
int D[100][100]; char s[100][100];
signed main(){
    int m, n; scanf("%d %d", &m, &n);
    for(int i = 0; i<m; ++i) for(int j = 0; j<n; ++j) scanf(" %c", &s[i][j]);
    std::queue<std::pair<int,int>> q;
    q.emplace(0, 0); D[0][0] = 1;
    while(!q.empty()){
        int i = q.front().first, j = q.front().second; q.pop();
        if(i+1<m && s[i][j] == 'D' || s[i][j] == 'B'){
            if(D[i+1][j] && D[i+1][j] == D[i][j] + 1){printf("%d\n%d %d", D[i+1][j], i+2, j+1); return 0;}
            else if(!D[i+1][j]){D[i+1][j] = D[i][j] + 1; q.emplace(i+1, j);} //two water lines meets
        }
        if(j+1<n && s[i][j] == 'R' || s[i][j] == 'B'){
            if(D[i][j+1] && D[i][j+1] == D[i][j] + 1){printf("%d\n%d %d", D[i][j+1], i+1, j+2); return 0;}
            else if(!D[i][j+1]){D[i][j+1] = D[i][j] + 1; q.emplace(i, j+1);} //two water lines meets
        }
        if(i && s[i-1][j] == 'D' || s[i-1][j] == 'B'){
            if(D[i-1][j] && D[i-1][j] == D[i][j] + 1){printf("%d\n%d %d", D[i-1][j], i, j+1); return 0;}
            else if(!D[i-1][j]){D[i-1][j] = D[i][j] + 1; q.emplace(i-1, j);} //two water lines meets
        }
        if(j && s[i][j-1] == 'R' || s[i][j-1] == 'B'){
            if(D[i][j-1] && D[i][j-1] == D[i][j] + 1){printf("%d\n%d %d", D[i][j-1], i+1, j); return 0;}
            else if(!D[i][j-1]){D[i][j-1] = D[i][j] + 1; q.emplace(i, j-1);} //two water lines meets
        }
    }
}
