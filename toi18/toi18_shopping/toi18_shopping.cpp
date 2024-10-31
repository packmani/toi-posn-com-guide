//toi18_shopping
#include <cstdio>
int qs[2][500000];
int sum(int t, int l, int r){
    return qs[t][r] - ((l)? qs[t][l-1] : 0);
}
signed main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0, x; i<n; ++i){
        scanf("%d", &x);
        if(x < 0) qs[1][i] = -x;
        else qs[0][i] = x;
        if(i){qs[0][i] += qs[0][i-1]; qs[1][i] += qs[1][i-1];}
    }
    while(m--){
        int x, h; scanf("%d %d", &x, &h);
        int low = x, high = n-1, j = -1;
        while(low <= high){
            int mid = low + ((high-low)>>1), tmp = sum(1, x, mid);
            if(tmp < h){
                low = mid+1; j = mid;
            }else if(tmp > h){
                high = mid-1;
            }else if(tmp == h){
                high = mid-1; j = mid;
            }
        }
        if(j == -1){puts("0"); continue;}
        printf("%d\n", sum(0, x, j));
    }
}
