#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll k, vector<ll> &a) {
    ll l = 0, r = k;
    ll cnt = 0;
    for(ll i = 0; i < k; i++) {
        if(a[i] < 2*a[i+1]) cnt++;
    }
    ll ans = 0;
    if(cnt == k) ans++;

    while(r < n-1) {
        if(a[l] < 2*a[l+1]) cnt--;
        if(a[r] < 2*a[r+1]) cnt++;
        if(cnt == k) ans++;
        l++;
        r++;
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
        ll n, k;
        cin>>n>>k;
        vector<ll> a(n);
        for(auto &num: a) cin>>num;
        cout<<solve(n, k, a)<<endl;
    }
    return 0;
}