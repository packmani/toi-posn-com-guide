//toi6_domino
//recursion
#include <stdio.h>
int n;
char s[33];
void f(int i, int j){ // i -> index, j current index of string (size - 1)
    if(i > n) return;
    if(i == n){
        for(int k = 0; k<j; k += 2) printf("%c%c\n", s[k], s[k+1]);
        puts("E"); return;
    }
    s[j] = s[j+1] = '-'; f(i+1, j+2);
    s[j] = s[j+1] = '|'; f(i+2, j+2); 
}

signed main(){
    scanf("%d", &n);
    f(0, 0);
}
