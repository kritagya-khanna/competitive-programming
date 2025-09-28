#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, vector<ll>&a) {
    ll x = LLONG_MAX, y = LLONG_MAX;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(x > y) swap(x, y);
        if(a[i] <= x) x = a[i];
        else if(a[i] <= y) y = a[i];
        else{
            x = a[i];
            ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(auto &num: a) cin>>num;
        cout<<solve(n, a)<<endl;
    }
    return 0;
}