//toi3_block
//brute force simulation
#include <cstdio>
#include <algorithm>
char s[5][5], c;
std::pair<int,int> del[20];
int m, n, p, sz, px[4] = {-1, 0, 1, 0}, py[4] = {0, -1, 0, 1}; // px and py for walking in 4 direction
int V(int i, int j){ return i>=0 && j>=0 && i<m && j<n;} //check if (i, j) is on grid?
int A(int i, int j){ return 'A' <= s[i][j] && s[i][j] <= 'Z';} //check if s[i][j] is uppercase alphabet?
int not_ok(){ // check whether there is adjacent same character?
	for(int i = 0; i<m; ++i){
		for(int j = 0; j<n; ++j){
			if(!A(i, j)) continue;
			for(int w = 0; w<4; ++w){
				if(V(i + px[w], j + py[w]) && s[i][j] == s[i + px[w]][j + py[w]]) return 1;
			}
		}
	}
	return 0;
}
signed main(){
	scanf("%d %d", &m, &n); 
	for(int i = 0; i<m; ++i) for(int j = 0; j<n; ++j) scanf(" %c", &s[i][j]);
	int l, x, y; scanf("%d", &l);
	while(l--){
		scanf("%d %d %c", &x, &y, &c);
		int d = (c == 'L') ? -1 : +1; // if c = 'L' -> y' = y-1, else if c = 'R' -> y' = y+1
		if(!V(x, y) || !V(x, y+d)){ p -= 5; continue;} //out of grid
		if(!A(x, y) || s[x][y+d] != '-'){ p -= 5; continue;} //(x, y) is not alphabet or (x, y+d)
		c = s[x][y]; s[x][y] = '-';  //change s[x][y] to space
		for(y += d; V(x, y) && s[x][y] == '-'; ++x); //go down till you cant go (till there is not (-) left)
		s[x-1][y] = c; //drop in this block 
		do{
			for(int i = sz = 0; i<m; ++i){ //check adjacent same character
				for(int j = 0; j<n; ++j){
					if(!A(i, j)) continue;
					for(int w = 0; w<4; ++w){
						x = i + px[w]; y = j + py[w];
						if(V(x, y) && s[x][y] == s[i][j]) del[sz++] = {x, y}; //del is to keep (i, j) that will be removed
					}
				}
			}
			sort(del, del+sz); p += 5 * (sz = unique(del, del+sz) - del);  // sort and unique to remove duplicate elements
			for(int i = 0; i<sz; ++i) s[del[i].first][del[i].second] = '-'; // remove the block 
			for(int i = 0; i<m-1; ++i){
				for(int j = 0; j<n; ++j){
					if(A(i, j) && s[i+1][j] == '-') s[i+1][j] = s[i][j], s[i][j] = '-'; // push down elements
				}
			}
		}while(not_ok()); //do till there is no change
	}	
	printf("%d\n", p); //print out the score
	for(int i = 0; i<m; ++i){
		for(int j = 0; j<n; ++j) printf("%c ", s[i][j]); puts("");
	}
}
