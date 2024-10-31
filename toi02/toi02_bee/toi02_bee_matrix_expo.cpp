//toi2_bee
//Matrix exponentiation
#include <cstdio>
#include <array>
using namespace std;
using Matrix = array<array<int,2>, 2>;
Matrix mul(Matrix a, Matrix b){
    Matrix res = {{{0, 0}, {0, 0}}};
    for(int i = 0; i<2; ++i){
        for(int j = 0; j<2; ++j){
            for(int k = 0; k<2; ++k){
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}
int fib(int n){ // log(n)
    Matrix base = {{{1, 0}, {0, 1}}}, m = {{{1, 1}, {1, 0}}};
    for(; n; n>>=1, m = mul(m, m)) if(n&1) base = mul(base, m); //binary exponentiation
    return base[0][1];
}
signed main(){
    for(int x; ; ){scanf("%d", &x); {if(!~x)break;} printf("%d %d\n", fib(x+3)-1, fib(x+4)-1);}
}
