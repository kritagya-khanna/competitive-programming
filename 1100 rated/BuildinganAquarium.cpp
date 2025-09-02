#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool helper(ll n , ll x, ll mid, vector<ll> &v){
    ll ans = 0;
    for(auto &num: v){
        ll temp = mid - num;
        ans += temp*(temp>0);
    }
    return ans <= x;
}

ll solve(ll n, ll x, vector<ll> &v){
    ll mini = LLONG_MAX, maxi = x;
    for(auto &num: v) {
        mini = min(mini, num);
    }
    maxi += mini;

    ll ans;
    while(mini <= maxi){
        ll mid = mini + (maxi - mini)/2;
        if(helper(n, x, mid, v)){
            mini = mid + 1;
            ans = mid;
        }
        else maxi = mid - 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ll n, x;
        cin>>n>>x;
        vector<ll> v(n);
        for(ll i = 0; i < n; i++) cin>>v[i];
        cout<<solve(n, x, v)<<endl;
    }
    return 0;
}