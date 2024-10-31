//toi14_plantation
//closest pair of point using dnc
#include <cstdio>
#include <algorithm>
#include <cmath>
#define F first
#define S second
typedef long long ll;
using namespace std;
ll sq(ll x){return x*x;}
pair<int,int> P[100000];
int st[100000];
bool by_y(int i, int j){return P[i].S < P[j].S;}
double cl(int l, int r){
    if(r-l < 3){
        double mn = 2e18;
        for(int i = l; i<r; ++i){
            for(int j = i+1; j<=r; ++j){
                double w = sqrt(sq(P[i].F - P[j].F) + sq(P[i].S - P[j].S)); // euclidean distance
                mn = min(mn, w);
            }
        }
        return mn;
    }
    int m = l + ((r-l)>>1), sz = 0;
    double d = min(cl(l, m), cl(m+1, r));
    for(int i = l; i<=m; ++i) if(P[m].F - P[i].F < d) st[sz++] = i; //in the middle stripe
    for(int i = m+1; i<=r; ++i) if(P[i].F - P[m].F < d) st[sz++] = i; //in the middle stripe
    sort(st, st+sz, by_y); //sort by y
    for(int i = 0; i<sz; ++i){ 
        for(int j = i+1; j<sz && P[st[j]].S - P[st[i]].S < d; ++j){ //run in constant time
            double w = sqrt(sq(P[st[i]].F - P[st[j]].F) + sq(P[st[i]].S - P[st[j]].S));
            d = min(d, w);
        }
    }
    return d;
}
signed main(){
    int w; scanf("%d", &w);
    while(w--){
        int n, r, d; scanf("%d %d %d", &n, &r, &d);
        for(int i = 0, x, y; i<n; ++i){scanf("%d %d", &x, &y); P[i] = make_pair(x, y);}
        sort(P, P+n); //sort by x
        if(cl(0, n-1) >= d+r+r) puts("Y");
        else puts("N");
    }
}
