//toi2_bee
//dynamic programming
#include <cstdio>
int f[25];
signed main(){
    f[0] = 1; f[1] = 2;
    for(int i = 2; i<=24; ++i) f[i] = f[i-1] + f[i-2] + 1;
    for(int x; ;){scanf("%d", &x); {if(x < 0) break;} printf("%d %d\n", f[x], f[x]+f[x-1]+1);}
}
