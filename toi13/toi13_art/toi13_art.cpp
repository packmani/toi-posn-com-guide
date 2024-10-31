//toi_13 art
//sweep line + fenwick tree (2n)*log(2n) + nlog^2(M)
#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
vector<pair<int,int>> O[4000002];
int coord[200005];
const int M = 1000005;
ll bit[M];
void upd(int i, ll val){for(; i<M; i+=i&-i) bit[i] += val;}
ll qry(int i){ll res = 0; for(; i; i-=i&-i) res += bit[i]; return res;}
signed main(){
    int n, t; scanf("%d %d", &n, &t);
    for(int i = 0, s, h, w, o, j = 0; i<n; ++i){
        scanf("%d %d %d %d", &s, &h, &w, &o);
        O[s].emplace_back(h, +o);
        O[s+w].emplace_back(h, -o);
        coord[j++] = s; coord[j++] = s+w;
    }
    sort(coord, coord+(n<<1)); int m = unique(coord, coord+(n<<1)) - coord;
    ll cnt = 0;
    for(int i = 0; i<m+1; ++i){
        ll x = coord[i], nx = coord[i+1];
        for(pair<int,int> it: O[x]){
            int h = it.first, o = it.second;
            upd(1, +o); upd(h+1, -o);
        }
        int low = 1, high = M;
        ll lb = 0, rb = 0;
        while(low <= high){
            int mid = low + ((high-low)>>1), tmp = qry(mid);
            if(t == tmp){high = mid-1; lb = mid;}
            else if(t < tmp) low = mid+1;
            else high = mid-1;
        }
        if(lb){
            low = lb; high = M;
            while(low <= high){
                int mid = low + ((high-low)>>1), tmp = qry(mid);
                if(t == tmp){low = mid+1; rb = mid;}
                else if(t < tmp) low = mid+1;
                else high = mid-1;
            }
            cnt += (nx - x) * (rb - lb + 1);
        }
    }
    printf("%lld", cnt);
}
