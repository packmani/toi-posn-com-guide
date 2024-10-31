//toi9_wizards
#include <cstdio>
#include <algorithm>
using namespace std;
int x_a[1500], y_a[1500], x_b[1500], y_b[1500], x_c[1500], y_c[1500];
pair<int,int> v[2250000], tg, *itr;
signed main(){
    int xt, yt, n, m = 0; scanf("%d %d %d", &xt, &yt, &n);
    for(int i = 0; i<n; ++i) scanf("%d %d", x_a+i, y_a+i);
    for(int j = 0; j<n; ++j){
        scanf("%d %d", x_b+j, y_b+j);
        for(int i = 0; i<n; ++i){
            v[m++] = make_pair(x_a[i] + x_b[j], y_a[i] + y_b[j]);
        }
    } 
    sort(v, v+m); m = unique(v, v+m) - v;
    for(int k = 0; k<n; ++k) scanf("%d %d", x_c+k, y_c+k);
    for(int l = 0, x_d, y_d; l<n; ++l){
        scanf("%d %d", &x_d, &y_d);
        for(int k = 0; k<n; ++k){
            tg = make_pair(xt - x_d - x_c[k], yt - y_d - y_c[k]);
            itr = lower_bound(v, v+m, tg);
            if(itr != v+m && *itr == tg){
                int sum_x = tg.first, sum_y = tg.second;
                for(int i = 0; i<n; ++i){
                    int rem_x = sum_x - x_a[i], rem_y = sum_y - y_a[i];
                    for(int j = 0; j<n; ++j){
                        if(x_b[j] == rem_x && y_b[j] == rem_y){
                            printf("%d %d\n%d %d\n%d %d\n%d %d", x_a[i], y_a[i], x_b[j], y_b[j], x_c[k], y_c[k], x_d, y_d);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
