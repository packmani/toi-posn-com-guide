//toi8_electricity
//sliding window minimum using deque
#include <cstdio>
#include <queue>
int dp[500000];
signed main(){
    int n, k; scanf("%d %d", &n, &k);
    std::deque<int> DQ; //stores indices
    for(int i = 0, p; i<n; ++i){
        scanf("%d", &p);
        while(!DQ.empty() && DQ.front() < i-k) DQ.pop_front(); //delete out bound element
        dp[i] = p + ((DQ.empty())? 0 : dp[DQ.front()]); //DQ.front() -> smallest element
        while(!DQ.empty() && dp[DQ.back()] >= dp[i]) DQ.pop_back(); //keep the elements in DQ sorted
        DQ.push_back(i);
    }
    printf("%d", dp[n-1]);
}
