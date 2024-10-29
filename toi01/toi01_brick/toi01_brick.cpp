//toi1_brick
//brute force / simulation
#include <cstdio>
char s[20][21];
int ls[20];
signed main(){
    int m, n; scanf("%d %d", &m, &n);
    for(int i = 0; i<m; ++i) scanf("%s", s[i]);
    for(int j = 0; j<n; ++j){
        ls[j] = m;
        for(int i = 0; i<m; ++i) if(s[i][j] == 'O'){ls[j] = i; break;}
    }
    for(int j = 0, x; j<n; ++j){
        scanf("%d", &x);
        while(x--) s[--ls[j]][j] = '#';
    }
    for(int i = 0; i<m; ++i) printf("%s\\n", s[i]);
}
