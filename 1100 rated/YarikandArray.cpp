#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, vector<ll> &v){
    ll maxi = INT_MIN, curr = 0;
    int prev = abs(v[0]%2) == 1 ? 0 : 1;
    for(ll i = 0; i < n; i++){
        if(abs(v[i] % 2) != prev){
            prev = abs(v[i] % 2);
            curr += v[i];
            maxi = max(curr, maxi);
            if(curr <= 0){
                curr = 0;
            }
        }
        else{
            curr = v[i] < 0? 0 :v[i];
            if(i < n-1 && v[i] < 0) prev = (v[i+1]%2);
            maxi = max(v[i], maxi);
        }
    }
    return maxi;
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