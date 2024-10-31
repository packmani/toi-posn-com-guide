//toi12_peak
#include <cstdio>
#include <algorithm>
int h[5000001], H[5000001]; 
signed main(){
    int n, k, m = 0; scanf("%d %d", &n, &k);
    for(int i = 1; i<=n; ++i) scanf("%d", h+i); 
    for(int i = 1; i<=n; ++i) if(h[i] > h[i-1] && h[i] > h[i+1]) H[m++] = h[i]; 
    std::sort(H, H+m); m = std::unique(H, H+m) - H;
    if(!m){puts("-1"); return 0;}
    if(m < k) for(int i = 0; i<m; ++i) printf("%d\n", H[i]);
    else for(int i = m-1; i>=m-k; --i) printf("%d\n", H[i]);
}
