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
    int n;cin >> n;
    vector<int> p(n);
    for(int &i:p){
        cin >> i;
    }
    int s,d,f;cin >> s >> d >> f;
    int m;cin >> m;
    vector<pii> adj[n+1];
    while(m--){
        int a,b,w;cin >> a >> b >> w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    vector<vector<vector<int>>> dist(n+1,vector<vector<int>>(f+1,vector<int>(2,1e18)));
    priority_queue<pair<pii,pii>,vector<pair<pii,pii>>,greater<pair<pii,pii>>> pq;
    pq.push({{0,s},{0,1}});
    dist[s][0][1] = 0;
    while(!pq.empty()){
        int city = pq.top().F.S;
        int money = pq.top().F.F;
        int oil = pq.top().S.F;
        int coupon = pq.top().S.S;
        pq.pop();
        if(oil<f && coupon && dist[city][f][0] > money){
            pq.push({{money,city},{f,0}});
            dist[city][f][0] = money;
        }
        if(oil+1<=f && dist[city][oil+1][coupon]>money+p[city-1]){
            pq.push({{money+p[city-1],city},{oil+1,coupon}});
            dist[city][oil+1][coupon] = money+p[city-1];
        }
        for(auto it:adj[city]){
            int destination = it.F;
            int weight = it.S;
            if(oil>=weight && dist[destination][oil-weight][coupon] > money){
                dist[destination][oil-weight][coupon] = money;
                pq.push({{money,destination},{oil-weight,coupon}});
            }
        }
    }
    cout << min(dist[d][f][0],dist[d][f][1]);
    return 0;
}
