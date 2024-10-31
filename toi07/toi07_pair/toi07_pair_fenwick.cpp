//toi7_pair
//fenwick tree
#include <cstdio>
#include <algorithm>
#include <functional>
typedef long long ll;
using namespace std;
pair<int,int> A[100000];
ll bit[2][100001]; //bit[0] -> sum of a[i] which a[i] > a[j], bit[1] -> count of a[i] which a[i] > a[j]
void upd(int j, int i, ll val){for(; i<=100000; i+=i&-i) bit[j][i] += val;}
ll qry(int j, int i){ll res = 0; for(; i; i-=i&-i) res += bit[j][i]; return res;}
signed main(){
    int n; scanf("%d", &n);
    for(int i = 0, a, b; i<n; ++i){
        scanf("%d %d", &a, &b);
        A[i] = make_pair(a, b);
    }
    sort(A, A+n, greater<pair<int,int>>()); //sort by a in non-increasing order
    ll tot = 0;
    for(int i = 0; i<n; ++i){
        int a = A[i].first, b = A[i].second;
        ll sum = qry(0, b-1), cnt = qry(1, b-1);
        tot += a * cnt + sum; 
        //tot += (a[j] + a[i1]) + (a[j] + a[i2]) + (a[j] + a[i3]) + ... + (a[j] + a[icnt])
        //tot += a[j] * cnt + sum(a[i])
        upd(0, b, a); upd(1, b, 1); 
    }
    printf("%lld", tot);
}
