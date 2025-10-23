#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll k, vector<ll> &a){
    if(k >= 3) return 0;
    vector<ll> diff;

    for(ll i = 0; i  < n; i++){
        for(ll j = i + 1; j < n; j++){
            diff.push_back(abs(a[i] - a[j]));
        }
    }

    sort(diff.begin(), diff.end());
    ll ans = LLONG_MAX;
    for(auto &num: a){
        ans = min(ans, num);
    }
    ans = min(ans, diff[0]);

    if(k == 1) return ans;

    for(int i = 0; i < n; i++){
        auto it = lower_bound(diff.begin(), diff.end(), a[i]);
        if( it != diff.end()){
            ans = min(ans, abs(*it - a[i]));
        }
        if(it != diff.begin()){
            it--;
            ans = min(ans, abs(*it - a[i]));
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
        ll n, k;
        cin>>n>>k;
        vector<ll> a(n);
        for(auto &num: a) cin>>num;
        cout<<solve(n, k, a)<<endl;
    }
    return 0;
}