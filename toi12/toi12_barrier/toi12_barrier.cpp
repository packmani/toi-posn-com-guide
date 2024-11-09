//toi12_barrier
//sliding window minimum
#include <stdio.h>
#define N 6000001
#define dN 12000001
int qs[N], dq[dN], f, b, mx, l;
int sz(){ return b-f+1;}
signed main(){
    int n, w; scanf("%d %d", &n, &w);
    dq[f = b = n] = 0;
    for(int i = 1, j; i<=n; dq[++b] = i++){
        scanf("%d", qs+i); qs[i] += qs[i-1];
        while(sz() && dq[f] < i-w) f++;
        if(sz()){
            int tmp = qs[i] - qs[j = dq[f]];
            if(tmp > mx || (tmp == mx && i-j < l)) mx = tmp, l = i-j;
        }
        while(sz() && qs[dq[b]] >= qs[i]) b--;
    }
    printf("%d\n%d", mx, l);
}
