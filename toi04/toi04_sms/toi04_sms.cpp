//toi4_sms
//brute force implementation
#include <stdio.h>
char a[9][4] = {{'.','.','.','.'}, {'A','B','C','.'}, {'D','E','F','.'}, {'G','H','I','.'}, {'J','K','L','.'}, {'M','N','O','.'}, {'P','Q','R','S'}, {'T','U','V','.'}, {'W','X','Y','Z'}}, sms[86];
int sz[9] = {0, 3, 3, 3, 3, 3, 4, 3, 4};
//o is current size of sms
//(i, j) in 3x3 grid -> 3*i+j in 1d grid
int main(){
    int n, s, m, o = 0; scanf("%d %d %d", &n, &s, &m); --m; 
    int i = (s > 3) + (s > 6), j,  h, v;
    if(1 < s < 4) j = (s > 1) + (s > 2);
    if(3 < s && s < 7) j = (s > 4) + (s > 5);
    if(6 < s && s < 10) j = (s > 7) + (s > 8);
    if(--s) sms[o++] = a[3*i+j][m%sz[3*i+j]]; //if (s != 1) append the character
    //s -> (i, j)
    int cnt = 0;
    for(--n; n--; ){
        scanf("%d %d %d", &h, &v, &m); --m;
        if(!((i+=v)+(j+=h))){ if((o-=(m+1)) < 0) o = 0;} // 1 -> delete m times (if o < 1 - > o = 0) 
        else sms[o++] = a[3*i+j][m%sz[3*i+j]];  //append the character
    }
    sms[o] = '\0';
    o ? printf("%s", sms) : printf("null");
}
