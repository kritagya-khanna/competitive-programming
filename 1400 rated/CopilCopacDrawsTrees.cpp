#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
map<pair<ll, ll>, ll> ind;


ll bfs(){
    queue<pair<pair<ll, ll>, ll>> q;
    for(auto &n: adj[1]) q.push({{n, 1}, 1});
    ll ans = 1;
    while(!q.empty()){
        ll node = q.front().first.first;
        ll par = q.front().first.second;
        ll itr = q.front().second;
        q.pop();
        ans = max(ans, itr);

        for(auto &n : adj[node]){
            ll nItr = itr;
            if(par != n){
                if(ind[{node, n}] < ind[{par, node}]) nItr++;
                ans = max(ans, nItr);
                q.push({{n, node}, nItr});
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        vector<pair<ll ,ll>> edges(n-1);
        for(ll i = 0; i < n-1; i++) 
            cin>>edges[i].first>>edges[i].second;  
            
        adj.assign(n+1, vector<ll>());
        for(ll i = 0; i < n-1; i++){
            ind[{edges[i].first, edges[i].second}] = i;
            ind[{edges[i].second, edges[i].first}] = i;
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        cout<<bfs()<<endl;
    }
    return 0;
}