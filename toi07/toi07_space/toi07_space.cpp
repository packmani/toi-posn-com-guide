//toi7_space
//bitmask brute force
#include <cstdio>
char a[16], b[16];
signed main(){
    int n; scanf("%d", &n); a[n] = b[n] = '\0';
    for(int mask = 0; mask < (1<<n); ++mask){ //run from [0, 2^n-1]
        for(int j = 0; j<n; ++j) a[n-j-1] = b[n-j-1] = (mask>>j&1) + '0'; 
        for(int j = n-1; j>=0; --j){
            if(a[j] == '0'){b[j] = '1'; /*add 1*/ printf("%s %s\n", a, b); b[j] = '0'; /*turn b back to a*/} //b have more 1 than a
        }
    }
}
