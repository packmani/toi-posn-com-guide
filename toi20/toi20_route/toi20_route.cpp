#include<bits/stdc++.h>
using namespace std;
int n,m,num;
vector<int> weights;

vector<pair<int,int>> route(int N,vector<int> W) {
  vector<pair<int,int>> result;
  int edges = W.size();
  int nodes = 1;
  vector<int> curnodes;
  //greedily try to stick as many nodes together until the unused nodes form a tree
  //edges-result.size() -> edges left, N-nodes -> edges required to form a tree
  while(edges-result.size()>N-nodes)
  {
    curnodes.push_back(nodes);
    for(int i=1;i<curnodes.size();i++)
    {
      result.push_back({i,nodes});
      if(edges-result.size()==N-nodes) break;
    }
    nodes++;
  }
  //connect to other nodes to form a tree
  for(int i=nodes;i<N;i++)
    result.push_back({i,i+1});
  
  return result;
}

//------------------FOR TESTING----------------------------
/*
int32_t main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for(int i=0;i<m;i++)
  {
    cin >> num;
    weights.push_back(num);
  }
  auto edges = route(n,weights);
  for(int i=0;i<edges.size();i++)
  {
    cout << edges[i].first << ' ' << edges[i].second << '\n';
  }
}
*/
