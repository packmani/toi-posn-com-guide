//toi5_tug
//greedy
#include <cstdio>
#include <algorithm>
int a[2000], b[2000];
signed main(){
    int n, i, A; scanf("%d", &n);
    for(i = 0; i<n; scanf("%d", &a[i++])); std::sort(a, a+n);
    for(i = 0; i<n; scanf("%d", &b[i++])); std::sort(b, b+n);
    for(i = A = 0; i<n; ++i) A += abs(b[i] - a[i]);
    printf("%d", A);
}
