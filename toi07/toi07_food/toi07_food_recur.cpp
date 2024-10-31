//toi7_food
//find all possible permutation using recursion
#include <cstdio>
int n, m, x, a[10]; bool no[10];
void f(int i, int mask){ //mask keeps index of used elements, 1 -> used, 0 -> unused
    if(i == n){ //we have used all elements
        for(int j = 0; j<n; ++j) printf("%d ", a[j]+1); puts(""); return;
    }
    for(int j = 0; j<n; ++j){
        if(!i && !no[j]){ a[i] = j; f(i+1, mask ^ (1<<j)); } //if this is the first one, we cannot put the banned one
        else if(i && !(mask>>j&1)){ a[i] = j;/*put j in i slot*/ f(i+1, mask ^ (1<<j)); /*insert to used elements set(mask)*/} 
    }
}        
signed main(){
    scanf("%d %d", &n, &m);
    while(m--){scanf("%d", &x); no[--x] = true;}
    f(0, 0);
}
