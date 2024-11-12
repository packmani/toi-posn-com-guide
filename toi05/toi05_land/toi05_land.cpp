//toi5_land
//brute force 
//std::next_permutation
#include <cstdio>
#include <algorithm>
std::pair<int,int> p[9];
double a[3][3], b[3][3], add, sum, mn = 2e9; //be aware big enough ? 
signed main(){
    int m, n, sz; scanf("%d %d", &m, &n);
    for(int i = sz = 0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            scanf("%lf", &a[i][j]); p[sz++] = {i, j};
        }
    }
    //please check whether p is sorted ? 
    do{
        for(int i = 0; i<m; ++i) for(int j = 0; j<n; ++j) b[i][j] = a[i][j]; //copy original values
        for(int i = sum = 0; i<sz; ++i){
            int x = p[i].first, y = p[i].second;
            sum += b[x][y]; add = b[x][y] * 0.1;
            for(int px = -1; px <= 1; ++px){
                for(int py = -1; py <= 1; ++py){ // 8 directions
                    if(!px && !py) continue;
                    int xx = x + px, yy = y + py;
                    if(~xx && ~yy && xx<m && yy<n) b[xx][yy] += add; //check if inside grid
                }
            }
        }
        if(sum < mn) mn = sum;
    }while(std::next_permutation(p, p+sz)); //try all possible picking orders
    printf("%.2lf", mn);
}
