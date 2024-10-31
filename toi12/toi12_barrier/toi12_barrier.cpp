//toi12_barrier
//sliding window minimum using deque
#include <cstdio>
#include <queue>
using namespace std;
int qs[6000000];
signed main(){
    int n, w, prf_sum = 0, mx = 0, sz = 0; scanf("%d %d", &n, &w);
    deque<int> dq;
    for(int i = 0, v; i<n; ++i){
        scanf("%d", &v); prf_sum += v; qs[i] = prf_sum;
        if(i < w && (qs[i] > mx || (qs[i] == mx && i+1 < sz))){mx = qs[i]; sz = i+1;}
        while(!dq.empty() && dq.front() < i-w) dq.pop_front();
        if(!dq.empty()){
            int F = dq.front(), tmp = qs[i] - qs[F];
            if(tmp > mx || (tmp == mx && i-F < sz)){mx = tmp; sz = i-F;}
        }
        while(!dq.empty() && qs[dq.back()] >= qs[i]) dq.pop_back();
        dq.push_back(i);
    }
    printf("%d\n%d", mx, sz);
}
