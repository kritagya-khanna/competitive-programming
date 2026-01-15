#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> mp;

bool bs(ll time, ll n, ll m) {
    ll val = 0;
    for(ll i = 1; i <= n; i++){
        val += min(mp[i], time);
        val += ((time - min(mp[i], time))/2);
    }
    return val >= m;
}

ll solve(ll n, ll m, vector<ll> &v) {
    ll low = 1;
    ll high = 2*m;
    ll ans = 0;
    while(low <= high) {
        ll mid = low + (high - low)/2;
        if(bs(mid, n, m)){
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
        ll n, m;
        cin>>n>>m;     
        mp.assign(n+1, 0);
        vector<ll> v(m);
        for(auto &num: v) cin>>num;

        for(auto &it: v) mp[it]++;
        cout<<solve(n, m, v)<<endl;
    }
    return 0;
}