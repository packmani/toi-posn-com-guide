#include <cstdio>
#include <algorithm>
char a[128], b[128], x[128];
int I[128]; 
signed main(){
	int L, K; scanf("%d %d %s %s %s", &L, &K, a, b, x);
	for(int i = 0; i<K; ++i) I[i] = i-K+1;
	for(int i = 0; i<L+K; ++i){
		for(int j = K-1; ~j; ++I[j--]){
			if(0 <= I[j] && I[j] < L){
				char t[3] = {a[I[j]], b[I[j]], x[j]};
				std::sort(t, t+3); x[j] = t[1];
			}	
		}
	}
	printf("%s", x);
}
