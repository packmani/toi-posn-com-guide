//toi6_schedule
//sweep line 
#include <cstdio>
#include <algorithm>
#define F first
#define S second
#define N 500000
std::pair<int,int> s[N], e[N]; //s -> starting of interval, e -> ending of interval
//s_i = e_i = {point, index}
int n, K, m, i, j, k, x, cur, ok[N]; //ok[i] check if did you insert i ?  
signed main(){
    scanf("%d %d %d", &n, &K, &m);
    for(i = 0; i<n; ++i) scanf("%d %d", &s[s[i].S = i].F, &e[e[i].S = i].F);
    std::sort(s, s+n); std::sort(e, e+n); // sort by time 
    //cur keeps current number slots used
    for(i = 0; i<n; i = j){
        for(x = s[i].F; k<n && e[k].F < x; ++k) cur -= (ok[e[k].S]); //remove eventpoint before x
        for(; j<n && s[j].F == x; ++j){
            if(cur < K) cur += (ok[s[j].S] = 1); //add
        }
        for(; k<n && e[k].F == x; ++k) cur -= (ok[e[k].S]); //remove only if we have inserted 
        //remove contribution of event that ended at x
    }
    while(m--){
        scanf("%d", &i); 
        ok[i-1] ? printf("Y ") : printf("N ");
    }
}
