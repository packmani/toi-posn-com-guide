//toi4_school
//binary search + 2d prefix sum
#include <cstdio>
#include <queue>
const int px[4] = {-1, 0, 1, 0}, py[4] = {0, -1, 0, 1};
char s[64][65];
int C[64][64], qs[64][64], t[2048], ch[2048], n, m, c, sz;
int QS(int i, int j){ return ~i && ~j && i<m && j<n ? qs[i][j] : 0;}
signed main(){	
	scanf("%d %d", &n, &m);
	for(int i = 0; i<m; ++i) scanf("%s", s[i]);
	std::queue<std::pair<int,int>> q; 
	for(int i = 0; i<m; ++i){ 
		for(int j = 0; j<n; ++j){
			if(s[i][j] == 'P' && !C[i][j]){
				C[i][j] = ++c; q.emplace(i, j);
				while(!q.empty()){
					int ii = q.front().first, jj = q.front().second; q.pop();
					for(int w = 0; w<4; ++w){
						int x = ii + px[w], y = jj + py[w];
						if(~x && ~y && x<m && y<n && s[x][y] == 'P' && !C[x][y]) C[x][y] = c, q.emplace(x, y);
					}
				}
			}
			qs[i][j] = QS(i-1, j) + QS(i, j-1) - QS(i-1, j-1) + (s[i][j] == 'T'); //2d prefix sum
		}
	}
	int low = 0, high = (m < n) ? m : n, mx, cnt = m*n; //binary search on square size 
	while(low <= high){
		int mid = low + ((high-low)>>1), ok = 0;
		for(int i = mid-1; !ok && i<m; ++i){
			for(int j = mid-1; !ok && j<n; ++j){
				if(!(QS(i, j) - QS(i-mid, j) - QS(i, j-mid) + QS(i-mid, j-mid))) ok = 1; //there is no 'T' in this square
			}
		}
		ok ? low = (mx = mid) + 1 : high = mid - 1; //update bound
	}
	if(!mx){ printf("0 0"); return 0;} 
	for(int i = mx-1, x, y; i<m; ++i){
		for(int j = mx-1; j<n; ++j){
			if(!(QS(i, j) - QS(i-mx, j) - QS(i, j-mx) + QS(i-mx, j-mx))){ // there is no 'T' in this square of size mx
				for(sz = 0, x = i; x+mx != i; --x) for(y = j; y+mx != j; --y) if(C[x][y]) t[sz++] = C[x][y]; 
				for(x = c = 0; x<sz; ++x) if(!ch[t[x]]) c += (ch[t[x]] = 1); //check distint ponds
				for(x = 0; x<sz; ch[t[x++]] = 0); //clear
				if(c < cnt) cnt = c; //update cnt if found better
			}
		}
	}
	printf("%d %d", mx*mx, cnt);
}
