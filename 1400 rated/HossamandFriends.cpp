#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll m, vector<vector<ll>> &v) {

    vector<ll> nE(n+1, 0);
    for(ll i = 0; i < m; i++){
        ll b = max(v[i][0], v[i][1]);
        ll s = min(v[i][0], v[i][1]);
        nE[b] = max(s, nE[b]);
    }

    for (int i = 1; i <= n; i++) {
        nE[i] = max(nE[i], nE[i - 1]);
    }

    ll ans = 0;
    for(int i = 1; i < n+1; i++)
        ans += (i - nE[i]);

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
        ll m;
        cin>>n>>m;
        vector<vector<ll>> v(m, vector<ll>(2));
        for(auto &arr: v){
            for(auto &ele: arr) cin>>ele;
        }
        cout<<solve(n, m, v)<<endl;
    }
    return 0;
}