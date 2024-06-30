//TOI19-Range
//fenwick tree
#include <cstdio>
#include <algorithm>
using namespace std;
int L[400000], R[400000], cp[400000], idx[400000], bit[400001], Ans[400000], n, m = 0;
bool cmp(int i, int j){return make_pair(R[i], -L[i]) < make_pair(R[j], -L[j]);}
int qry(int i){int res = 0; for(; i; i-=i&-i) res = max(res, bit[i]); return res;}
void upd(int i, int val){for(; i<=m; i+=i&-i) bit[i] = max(bit[i], val);}
signed main(){
    scanf("%d", &n);
    for(int i = 0; i<n; ++i){scanf("%d %d", L+i, R+i); cp[m++] = L[i]; idx[i] = i;}
    sort(idx, idx+n, cmp); sort(cp, cp+m); m = unique(cp, cp+m) - cp;
    for(int i = 0; i<n; ++i){
        int j = upper_bound(cp, cp+m, L[idx[i]]) - cp;
        upd(m-j+1, Ans[idx[i]] = qry(m-j+1) + 1);
    }    
    printf("%d\n", *max_element(Ans, Ans+n));
    for(int i = 0; i<n; ++i) printf("%d ", Ans[i]);
}
