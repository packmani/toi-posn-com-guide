//credit : Blackslex
//toi9_pipe
//brute force dfs
#include<bits/stdc++.h>

using namespace std;

int n, m, a[305][305];
vector<int> v;
// 1 -> right (R)
// 2 -> down (D)
// 3 -> left (L)
// 4 -> up (U)
int pipe (int x, int y, int k) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    int o;
    if (a[x][y] == 31) { // 31 = 21 + 22
        if (k == 1 || k == 3) o = 22, a[x][y] = 21; //horizontal 
        else o = 21, a[x][y] = 22; //vertical  (a[x][y] to another one for future dfs)
    } else o = a[x][y], a[x][y] = 0;
    if (o == 11) { 
        if (k == 1) return pipe(x - 1, y, 4) + 1; //R -> U
        else if (k == 2) return pipe(x, y - 1, 3) + 1; //D -> L
    } else if (o == 12) {
        if (k == 3) return pipe(x - 1, y, 4) + 1; //L -> U
        else if (k == 2) return pipe(x, y + 1, 1) + 1; //D -> R
    } else if (o == 13) {
        if (k == 1) return pipe(x + 1, y, 2) + 1; //R -> D
        else if (k == 4) return pipe(x, y - 1, 3) + 1; //U -> L
    } else if (o == 14) {
        if (k == 3) return pipe(x + 1, y, 2) + 1; //L -> D
        else if (k == 4) return pipe(x, y + 1, 1) + 1; //U - > R
    } else if (o == 21) {
        if (k == 4) return pipe(x - 1, y, 4) + 1; //U -> U
        else if (k == 2) return pipe(x + 1, y, 2) + 1; //D -> D
    } else if (o == 22) {
        if (k == 3) return pipe(x, y - 1, 3) + 1; //L -> L
        else if (k == 1) return pipe(x, y + 1, 1) + 1; //R -> R
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < m; i++) { //down
        if (a[0][i] == 11 || a[0][i] == 12 || a[0][i] == 21 || a[0][i] == 31) v.emplace_back(pipe(0, i, 2));
    }
    for (int i = 0; i < m; i++) { //up
        if (a[n - 1][i] == 13 || a[n - 1][i] == 14 || a[n - 1][i] == 21 || a[n - 1][i] == 31) v.emplace_back(pipe(n - 1, i, 4));
    }
    for (int i = 0; i < n; i++) { //right
        if (a[i][0] == 11 || a[i][0] == 13 || a[i][0] == 22 || a[i][0] == 31) v.emplace_back(pipe(i, 0, 1));
    }
    for (int i = 0; i < n; i++) { //left
        if (a[i][m - 1] == 12 || a[i][m - 1] == 14 || a[i][m - 1] == 22 || a[i][m - 1] == 31) v.emplace_back(pipe(i, m - 1, 3));
    }
    printf("%d\n", v.size());
    for (auto e: v) printf("%d ", e);
}
