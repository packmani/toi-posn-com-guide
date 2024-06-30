//TOI19-Range 
//binary search
#include <cstdio>
#include <algorithm>
using namespace std;
int L[400000], R[400000], idx[400000], V[400000], Ans[400000], sz = 0;
bool cmp(int i, int j){return make_pair(R[i], -L[i]) < make_pair(R[j], -L[j]);}
signed main(){
    int n; scanf("%d", &n); 
    for(int i = 0; i<n; ++i){scanf("%d %d", L+i, R+i); idx[i] = i;}
    sort(idx, idx+n, cmp);
    for(int i = 0; i<n; ++i){
        int j = upper_bound(V, V+sz, -L[idx[i]]) - V;
        if(j == sz) ++sz;
        Ans[idx[i]] = j + 1;
        V[j] = -L[idx[i]];
    }
    printf("%d\n", *max_element(Ans, Ans+n));
    for(int i = 0; i<n; ++i) printf("%d ", Ans[i]);
}
