//toi17_1221
#include <bits/stdc++.h>
using namespace std;

int price[505];
long long e[505][505];
int c[505][505];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,Q; cin >> n >> m >> Q;
    for(int i=1;i<=n;i++)
        cin >> price[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            if(i!=j) {
                e[i][j] = price[i]+price[j];
                c[i][j] = 2;
            } else
                e[i][j] = 0;
        }
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        e[u][v] = w;
        e[v][u] = w;
    }            
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) 
                if(e[i][j] >= e[i][k]+e[k][j]) {
                    e[i][j] = e[i][k]+e[k][j];
                    //if(c[i][j] < c[i][k] + c[k][j])
                        c[i][j] = c[i][k] + c[k][j];
                }
            
    while(Q--) {
        int a,b;
        cin >> a >> b;
        cout << e[a][b] << " " << c[a][b] << endl;
    }
}
