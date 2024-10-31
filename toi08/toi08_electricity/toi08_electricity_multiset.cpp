//toi8_electricity
//multiset 
#include <cstdio>
#include <set>
int dp[500000]; // dp[i] = minimum cost to build from [0, i] using ith space to build
signed main(){
    int n, k; scanf("%d %d", &n, &k);
    std::multiset<int> ms;
    for(int i = 0, p; i<n; ++i){
        scanf("%d", &p);
        if(i > k) ms.erase(ms.find(dp[i-k-1])); //delete out of range element
        ms.insert(dp[i] = p + ((ms.empty())? 0 : *ms.begin())); //insert new element
    }
    printf("%d", dp[n-1]);
}
