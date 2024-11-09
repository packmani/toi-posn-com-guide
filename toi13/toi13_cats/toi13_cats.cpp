#include <cstdio>
#include <algorithm>
const int N = 2e6 + 5;
int a[N];
signed main(){
	int n; scanf("%d", &n);
	for(int i = 0; i<n; ++i) scanf("%d", a+i);
	int low = 0, high = *std::max_element(a, a+n), ans;
	while(low<=high){
		int mid = low + ((high-low)>>1);
		int x = -1; bool ch = true;
		for(int i = 0; i<n; ++i){
			if(a[i] > mid){
				if(x == -1){
					x = a[i];
				}else{
					if(x != a[i]){ch = false; break;}
					x = -1;
				}
			}
		}
		if(ch) high = mid-1, ans = mid;
		else low = mid+1;
	}
	printf("%d", ans);
}
