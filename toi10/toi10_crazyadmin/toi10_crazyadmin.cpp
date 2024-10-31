//toi10_crazyadmin
//binary search to find the minimum of maximum
#include <cstdio>
#include <algorithm>
int u[100];
signed main(){
    int m, o, mx = 0, sum = 0; scanf("%d %d", &m, &o);
    for(int i = 0; i<o; ++i){scanf("%d", u+i); mx = std::max(mx, u[i]); sum += u[i];}
    int low = mx, high = sum, ans;
    while(low <= high){
        int mid = low + ((high-low)>>1), cnt = 1; sum = 0;
        for(int i = 0; i<o; ++i){
            if(sum + u[i] <= mid) sum += u[i];
            else{++cnt; sum = u[i];}
        }
        if(cnt <= m){high = mid-1; ans = mid;}
        else low = mid+1;
    } 
    printf("%d", ans);
}
