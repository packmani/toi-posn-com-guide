//toi8_fighter
//brute force/simulation
#include <cstdio>
//(t = 0) -> even, (t = 1) -> odd
//(t^1) = flips bit (from 0 -> 1, 1 -> 0)
signed main(){
    int P, prv[2][2] = {{-1, -1}, {-1, -1}}/*prv[t] keep two most recent odd/even number*/ , damage[2] = {0, 0}; /*keep damages for odd and even*/
    scanf("%d", &P); 
    for(int i = 0, x, t; i<(P<<1); ++i){
        scanf("%d", &x); t = x&1;
        damage[t^1] += ((prv[t][0] >= 0 && prv[t][1] >= 0 && prv[t][0] == i-2 && prv[t][1] == i-1)? +3 : +1); //check if three consecutive
        if(damage[t^1] >= P){printf("%d\n%d", t, x); return 0;} //hp <= 0
        prv[t][0] = prv[t][1]; prv[t][1] = i;
        prv[t^1][0] = prv[t^1][1] = -1; //consecutive streak for opposite parity is ruined
    }
}
