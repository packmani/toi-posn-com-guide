//toi4_mountain
//brute force
#include <stdio.h>
#define I short
char a[11][90];
signed main(){
    I n, mx = 0, H = 100; scanf("%hd", &n);
    for(I i = 0; i<11; ++i){
        for(I j = 0; j<90; ++j) a[i][j] = '.';
    }
    while(n--){
        I s, h; scanf("%hd %hd", &s, &h); --s;
        I st = s, ed = s+2*h-1;
        if(10-h < H) H = 10-h;
        if(ed > mx) mx = ed;
        for(I i = 9; i >= 10-h; --i){
            if(a[i][st] != 'X'){
                if(a[i][st] == '\\') a[i][st] = 'v';
                else a[i][st] = '/';
            }
            for(I j = st+1; j != ed; ++j) a[i][j] = 'X';
            if(a[i][ed] != 'X'){
                if(a[i][ed] == '/') a[i][ed] = 'v';
                else a[i][ed] = '\\';
            }
            ++st; --ed;
        }
    }
    for(I i = H; i != 10; ++i){
        a[i][mx+1] = '\0';
        printf("%s\n", a[i]);
    }
}
