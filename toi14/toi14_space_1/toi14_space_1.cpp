#include <bits/stdc++.h>

#define pb push_back
#define ist insert
#define all(x) x.begin(), x.end()
#define int long long int
#define endl "\n"
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define F first
#define S second
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int32_t main() {
    fast;
    int n,m;cin >> n >> m;
    vector<vector<int>> adj(m,vector<int>(n));
    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        string s;cin >> s;
        for(int j=0;j<n;j++){
            adj[i][j] = s[j]=='1'?1:0;
        }
    }
    int a=0,b=0,c=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && adj[i][j]){
                vis[i][j] = 1;
                int minx = 1e18,maxx = -1e18,miny = 1e18,maxy = -1e18,count = 1;
                queue<pii> q;
                q.push({i,j});
                while(!q.empty()){
                    int nx = q.front().F;
                    int ny = q.front().S;
                    minx = min(nx,minx);
                    maxx = max(nx,maxx);
                    miny = min(ny,miny);
                    maxy = max(ny,maxy);
                    q.pop();
                    int gx[] = {1,-1,0,0};
                    int gy[] = {0,0,1,-1};
                    for(int k=0;k<4;k++){
                        int x = gx[k]+nx;
                        int y = gy[k]+ny;
                        if(0<=x&&x<m&&0<=y&&y<n&&adj[x][y]&&!vis[x][y]){
                            q.push({x,y});
                            vis[x][y] = 1;
                            count++;
                        }
                    }
                }
                int area = (maxx-minx+1)*(maxy-miny+1);
                int mn = min((maxx-minx+1),(maxy-miny+1));
                if(area == count){
                    a++;
                }
                else if(mn+(mn*(mn-1)) == count){
                    c++;
                }
                else{
                    b++;
                }
            }
        }
    }
    cout << a <<" "<<b<<" "<<c;
}
