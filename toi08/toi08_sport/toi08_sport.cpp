//toi8_sport
//recursion
#include <cstdio>
int k; char s[405];//make s global so no need to backtrack
void f(int i, int a, int b){// i is index of s
    if(a == k || b == k){s[i] = '\0'; printf("%s\n", s); return;}
    s[i] = 'W'; s[i+1] = ' '; f(i+2, a+1, b);
    s[i] = 'L'; s[i+1] = ' '; f(i+2, a, b+1);
}
signed main(){
    int a, b; scanf("%d %d %d", &k, &a, &b);
    f(0, a, b);
}
