//toi2_word
//brute force
#include <cstdio>
#include <cstring>
int m, n;
char s[25][26], t[26];
bool V(int i, int j){ return i >= 0 && j >= 0 && i < m && j < n;} //check if (i, j) is in the grid
bool same(char x, char y){ return (x == y) || (x + 'A' == y + 'a') || (x + 'a' == y + 'A');} //check if x and y is the same character 
signed main(){
    int k, sz, ch; scanf("%d %d", &m, &n);
    for(int i = 0; i<m; ++i) scanf("%s", s[i]);
    scanf("%d", &k);
    while(k--){
        scanf("%s", t); sz = strlen(t); 
        for(int i = ch = 0, x, y, w; !ch && i<m; ++i){
            for(int j = 0; !ch && j<n; ++j){
                for(int px = -1; !ch && px <= 1; ++px){
                    for(int py = -1; !ch && py <= 1; ++py){ //px & py will give all possible direction 
                        if(!px && !py) continue;
                        for(x = i, y = j, w = 0; V(x, y) && w < sz && same(s[x][y], t[w]); ++w, x += px, y += py){}
                        if(w == sz) printf("%d %d\n", i, j), ch = 1; //ch is to check that we have found the answer
                    }
                }
            }
        }
    }
}
