//toi7_bomb
//sort
#include <cstdio>
#include <algorithm>
std::pair<int,int> P[1000000];
signed main(){
    int n, mxY = 0; scanf("%d", &n);
    for(int i = 0, x, y; i<n; ++i){
        scanf("%d %d", &x, &y); P[i] = std::make_pair(-x, y); 
    }
    std::sort(P, P+n);
    //sort by x in descending order if x is equal sort by y in asceding order
    //we sort by x to solve for the condition x1 > x2 
    //if x is equal we loop in ascending order of y to make sure that y1 > y2 does not occur for the same x
    for(int i = 0; i<n; ++i){
        int x = -P[i].first, y = P[i].second;
        if(mxY <= y) printf("%d %d\n", x, y); //no point covers this point
        mxY = std::max(mxY, y);
    }
}
