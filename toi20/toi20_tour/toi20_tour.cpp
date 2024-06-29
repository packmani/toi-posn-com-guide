//TOI20-Tour
//sol แบบไม่ควรจะถูกต้อง
#include <bits/stdc++.h>
#define S second
#define F first
typedef long long ll;
using namespace std;
using pll = pair<ll,ll>;
vector<tuple<int,int,int>> g[200000];
int n, m, l, x, u, v, s, w;
vector<pll> Px, P_y;
void dfs(int u, ll ff, ll ss){
    if(u == n-1){Px.emplace_back(ff, ss); return;}
    for(tuple<int,int,int> &it: g[u]){
        tie(v, s, w) = it;
        dfs(v, ff + (!s) * w, ss + (s) * w);
    }
}
ll sq(ll x){return x * x;}
bool by_y(pll &a1, pll &a2){return a1.S < a2.S;}
const int K = 1000;
ll cl(int low, int high, vector<pll> &Py){
    int n = Py.size();
    if(n <= K){
        ll mn = LLONG_MAX;
        for(int i = low; i<=high; ++i){
            for(int j = i+1; j<=high; ++j){
                mn = min(mn, sq(Px[i].F - Px[j].F) + sq(Px[i].S - Px[j].S));
            }
        }
        return mn;
    }
    int mid = low + ((high-low)>>1), jl = 0, jr = 0;
    vector<pll> Pyl(mid-low+1), Pyr(high-mid);
    for(int i = 0; i<n; ++i){
        if(Py[i] <= Px[mid]) Pyl[jl++] = Py[i];
        else Pyr[jr++] = Py[i];
    }
    ll d = min(cl(low, mid, Pyl), cl(mid+1, high, Pyr));
    vector<pll> st;
    for(int i = 0; i<n; ++i){
        if(sq(Py[i].F - Px[mid].F) < d) st.push_back(Py[i]);
    }
    m = st.size();
    for(int i = 0; i<m; ++i){
        for(int j = i+1; j<m && sq(st[i].S - st[j].S) < d; ++j){
            d = min(d, sq(st[i].F - st[j].F) + sq(st[i].S - st[j].S));
        }
    }
    return d;
}
signed main(){
    scanf("%d %d %d", &n, &m, &l);
    while(l--) scanf("%d", &x);
    while(m--){
        scanf("%d %d %d %d", &u, &v, &s, &w); --u; --v; --s;
        g[u].emplace_back(v, s, w);
    }
    dfs(0, 0, 0);
    P_y = Px;
    sort(Px.begin(), Px.end()); sort(P_y.begin(), P_y.end(), by_y);
    if(!P_y.back().S){
        ll mn = LLONG_MAX;
        for(int i = 1; i<Px.size(); ++i) mn = min(mn, sq(Px[i].F - Px[i-1].F));
        printf("%lld", mn);
    }else{
        printf("%lld", cl(0, Px.size() - 1, P_y));
    }
}
