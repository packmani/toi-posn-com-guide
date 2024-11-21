//toi14_nbk48
//binary search
#include <cstdio>
#include <algorithm>
int qs[100000];
signed main(){
  int n, q, x; scanf("%d %d", &n, &q);
  for(int i = 0; i<n; ++i){
  	scanf("%d", qs+i); 
  	qs[i] += (i? qs[i-1] : 0);
  }
  for(int i = n-2; ~i; --i) if(qs[i+1] < qs[i]) qs[i] = qs[i+1];
  while(q--){
  	scanf("%d", &x);
  	printf("%d\n", (int)(std::upper_bound(qs, qs+n, x) - qs));
  }	
}
