//toi4_school
//dynamic programming 
//Flood Fill (BFS)
#include <cstdio>
#include <queue>
#include <algorithm>
const int px[4] = {-1, 0, 1, 0}, py[4] = {0, -1, 0, 1};
char s[64][65];
int C[64][64], dp[64][64], ch[2048], t[2048], n, m, c, mx, sz;
int DP(int i, int j){ return ~i && ~j && i<m && j<n ? dp[i][j] : 0;}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i<m; ++i) scanf("%s", s[i]);
	std::queue<std::pair<int,int>> q;
	//Flood fill to find pond number
	for(int i = 0; i<m; ++i){
		for(int j = 0; j<n; ++j){
			if(s[i][j] == 'P' && !C[i][j]){
				q.emplace(i, j); C[i][j] = ++c; //new component
				while(!q.empty()){
					int ii = q.front().first, jj = q.front().second; q.pop();
					for(int w = 0; w<4; ++w){ // 4 direction
						int x = ii + px[w], y = jj + py[w];
						if(~x && ~y && x<m && y<n && s[x][y] == 'P' && !C[x][y]) q.emplace(x, y), C[x][y] = c;
					}
				}
			}
			if(s[i][j] == 'T') continue;
			if((dp[i][j] = std::min({DP(i-1, j), DP(i, j-1), DP(i-1, j-1)}) + 1) > mx) mx = dp[i][j]; //square
		}
	}
	if(!mx){ printf("0 0"); return 0;}
	int cnt = m*n;
	for(int i =  0, x, y; i<m; ++i){
		for(int j = 0; j<n; ++j){
			if(dp[i][j] == mx){ //If max -> min pond numbers
				for(sz = 0, x = i; x+mx != i; --x) for(y = j; y+mx != j; --y) if(C[x][y]) t[sz++] = C[x][y]; 
				for(x = c = 0; x<sz; ++x) if(!ch[t[x]]) c += (ch[t[x]] = 1); //distinct pond no.
				for(x = 0; x<sz; ch[t[x++]] = 0); 
				if(c < cnt) cnt = c; //update if found better
			}
		}
	}
	printf("%d %d", mx*mx, cnt);
}
