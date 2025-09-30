#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isValid(ll n, vector<vector<ll>> &v, ll mid) {
    ll minP = 0, maxP = 0;

    for(ll i = 0; i < n; i++) {

        maxP += mid;
        minP -= mid;
        ll possibleS = max(minP, v[i][0]);
        ll possibleE = min(maxP, v[i][1]);
        // cout<<possibleS<<' '<<possibleE<<" ";

        if(possibleS > possibleE) return false;

        minP = possibleS;
        maxP = possibleE;
    }
    return true;
}

ll solve(ll n, vector<vector<ll>> &v) {
    ll low = 0, high = 1e9;
    while(low <= high){
        ll mid = (high + low)/2;
        if(isValid(n, v, mid)){
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        vector<vector<ll>> v(n, vector<ll>(2));
        for(auto &vec: v){
            ll a, b;
            cin>>a>>b;
            vec = {a, b};
        }
        
        cout<<solve(n, v)<<endl;

    }
    return 0;
}