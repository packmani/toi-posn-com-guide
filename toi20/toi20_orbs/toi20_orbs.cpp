#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int x[2000000];
multiset<int> A, B, C;
signed main(){
    int n, L, a, b; scanf("%d %d %d %d", &n, &L, &a, &b);
    for(int i = 1; i<=n; ++i) scanf("%d", x+i);
    sort(x+1, x+1+n);
    for(int i = 1; i<=a; ++i) A.insert(x[i]);
    for(int i = a+1; i<b; ++i) B.insert(x[i]);
    for(int i = b; i<=n; ++i) C.insert(x[i]);
    multiset<int>::iterator itr;
    for(int j = 0; j<L; ++j){
        itr = A.end(); --itr; int x = *itr; A.erase(itr);
        itr = C.begin(); int y = *itr; C.erase(itr);
        B.insert((x+y)>>1); B.insert(y-x);
        itr = B.begin(); A.insert(*itr); B.erase(itr);
        itr = B.end(); --itr; C.insert(*itr); B.erase(itr);
    }
    for(int x: A) printf("%d ", x);
    for(int x: B) printf("%d ", x);
    for(int x: C) printf("%d ", x);
}
