//toi9_wizards
//meet in the middle + find (binary search)
#include <cstdio>
#include <algorithm>
#include <tuple>
using namespace std;
int x[4][1500], y[4][1500];
tuple<int,int,int> v[2250000], tg, *itr;
signed main(){
    int xt, yt, n, m = 0; scanf("%d %d %d", &xt, &yt, &n);
    for(int t = 0; t<4; ++t){
        for(int i = 0; i<n; ++i) scanf("%d %d", &x[t][i], &y[t][i]);
    }
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            v[m++] = make_tuple(x[0][i] + x[1][j], y[0][i] + y[1][j], i); // a, b
        }
    }
    sort(v, v+m); m = unique(v, v+m) - v;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            tg = make_tuple(xt - x[2][i] - x[3][j], yt - y[2][i] - y[3][j], -1); // c, d
            itr = lower_bound(v, v+m, tg); //search ans
            if(itr != v+m){
                int f = get<0>(tg), s = get<1>(tg);
                int ff = get<0>(*itr), ss = get<1>(*itr), ii = get<2>(*itr);
                if(f == ff && s == ss){
                    printf("%d %d\n%d % d\n%d %d\n%d %d", x[0][ii], y[0][ii], f - x[0][ii], s - y[0][ii], x[2][i], y[2][i], x[3][j], y[3][j]);
                    return 0; //end immediately if answer found
                }
            }
        }
    }
}
