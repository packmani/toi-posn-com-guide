//toi7_car
//dynamic programming + backtracking
#include <cstdio>
bool ok[101][40]; int step[101]; //ok[i][j] can we be in lane j at time i?
signed main(){
    int m, n, t, x, I, J; scanf("%d %d %d", &m, &n, &t); ok[0][--n] = true;
    for(int i = 1; i<=t; ++i){
        for(int j = 0; j<m; ++j){
            scanf("%d", &x); 
            if(!x) ok[i][j] |= (ok[i-1][j])/*straight*/ | (j && ok[i-1][j-1])/*right*/ | (j+1<m && ok[i-1][j+1])/*left*/;
            if(i == t && ok[i][j]){I = t; J = j; break;} 
        }
    }
    //backtracking (from t to 0)
    while(I){
        //think in reverse manner
        if(ok[I-1][J]){step[--I] = 3;} 
        else if(ok[I-1][J-1]){step[--I] = 2; --J;}
        else if(ok[I-1][J+1]){step[--I] = 1; ++J;}
    }
    for(int i = 0; i<t; ++i) printf("%d\n", step[i]);
}
