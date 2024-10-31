//toi7_food
//finding all permutation using std::next_permutation()
#include <cstdio>
#include <algorithm>
bool no[10];
signed main(){
    int n, m, a[10], i = 0, x; scanf("%d %d", &n, &m);
    for(; i<m; ++i){scanf("%d", &x); no[x] = true; a[i] = i+1;}
    for(; i<n; ++i) a[i] = i+1;
    do{    
        if(no[a[0]]) continue; //contain banned item to be leftmost
        for(i = 0; i<n; ++i) printf("%d ", a[i]); puts("");
    }while(std::next_permutation(a, a+n));
}
