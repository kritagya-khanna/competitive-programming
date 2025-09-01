#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, vector<ll> &v){
    vector<ll> prefix(n);
    prefix[0] = v[0];
    for(ll i = 1; i < n; i++) prefix[i] += (v[i] + prefix[i-1]);
    ll ans = 0;
    for(int k = 1; k <= n; k++){
        if(n%k) continue;
        ll start = k-1;
        ll res = 0;
        ll maxi = prefix[start];
        ll mini = prefix[start];
        for(ll i = start + k; i < n; i += k){
            ll curr = prefix[i] - prefix[i-k];
            maxi = max(maxi, curr);
            mini = min(mini, curr);

        }
        ans = max(ans, maxi - mini);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i = 0; i < n; i++) cin>>v[i];
        cout<<solve(n, v)<<endl;
    }
    return 0;
}