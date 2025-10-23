#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool helper(ll k, ll n, vector<ll> &a, vector<ll> &b){
    for(ll i = k; i < n; i++){
        if(a[i-k] >= b[i]) return false;
    }
    return true;
}

ll solve(ll n, vector<ll> &a, vector<ll> &b) {
    ll ans = 0;
    ll low = 0, high = n;
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(helper(mid, n, a, b)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
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
        vector<ll> a(n), b(n);
        for(auto &num: a) cin>>num;
        for(auto &num: b) cin>>num;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout<<solve(n, a, b)<<endl;
    }
    return 0;
}