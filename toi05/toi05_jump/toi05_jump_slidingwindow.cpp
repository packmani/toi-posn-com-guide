//toi5_jump
//sliding window
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

signed main(){
    int n, k, mx = 0; scanf("%d %d", &n, &k);
    deque<int> dq;
    for(int i = 0, x; i<n; ++i){ //deque keep elements in range [x-k, x]
        scanf("%d", &x);
        while(!dq.empty() && dq.front() < x-k) dq.pop_front(); //pop out out of bound elements
        dq.push_back(x); mx = max(mx, (int)dq.size() - 1); 
    }
    printf("%d", mx);
}
