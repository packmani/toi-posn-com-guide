//toi3_filter
//range update
#include <stdio.h>
int d[3005]; //difference array
int f, h; // f pass 100%, h pass 50 %
signed main(){
	int W, H, n, x, a; scanf("%d %d %d", &W, &H, &n);
	while(n--){
		scanf("%d %d", &x, &a); ++d[x];
		if(x+a < W) --d[x+a];
	}
	for(int i = 1; i<W; ++i) d[i] += d[i-1]; //sweep
	for(int i = 0; i<W; ++i){
		if(d[i] == 1){++h;} if(!d[i]){++f;}
	}
	printf("%d %d", f*H, h*H);
}
