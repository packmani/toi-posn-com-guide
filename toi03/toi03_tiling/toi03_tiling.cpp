//toi3_tiling
//BFS Flood Fill
#include <cstdio>
#include <queue>
const int px[4] = {0, 0, -1, +1};
const int py[4] = {-1, 1, 0, 0};
                  /*L   R  U  D*/
int s[17][17], v[17][17], C[17][17], ans, ch;
signed main(){
	int n; scanf("%d", &n);
	for(int i = 0; i<n; ++i) for(int j = 0; j<n; ++j) scanf("%d", &s[i][j]);
	std::queue<std::pair<int,int>> q;
	for(int i = 0; i<n; ++i){
		for(int j = 0, cnt; j<n; ++j){
			if(!v[i][j]){
				q.emplace(i, j); v[i][j] = cnt = 1; 
				while(!q.empty()){ //bfs
					int ii = q.front().first, jj = q.front().second; q.pop();
					for(int w = 0; w<4; ++w){ //try to move in 4 directions
						int x = ii + px[w], y = jj + py[w];
						if(~x && ~y && x<n && y<n && !v[x][y] && s[x][y] == s[i][j]) q.emplace(x, y), cnt += (v[x][y] = 1); //keep number cells in this component 
					}
				}
				C[i][j] = cnt; 
			}
			if(i && s[i][j] == s[i-1][j]) C[i][j] = std::max(C[i-1][j], C[i][j]); // C[i][j] stores number of cells in the component that (i, j) is in
			if(j && s[i][j] == s[i][j-1]) C[i][j] = std::max(C[i][j-1], C[i][j]);
			if(C[i][j] == 3){ // if there is 3 cells in the component
				for(int k1 = ch = 0; !ch && k1<=1; ++k1){ // check if it forms the L shape ? 
					for(int k2 = 2; !ch && k2<=3; ++k2){
						int x1 = i + px[k1], y1 = j + py[k1], x2 = i + px[k2], y2 = j + py[k2];
						if(~x1 && ~y1 && x1<n && y1<n && ~x2 && ~y2 && x2<n && y2<n && s[x1][y1] == s[x2][y2] && s[i][j] == s[x1][y1]) ch = 1;
					}
				}
				ans += ch;
			}
		}
	}
	printf("%d", ans);
}
