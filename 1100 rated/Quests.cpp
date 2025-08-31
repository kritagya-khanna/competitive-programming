#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll k, vector<ll> &a, vector<ll> &b){
    ll maxi = 0, prev = 0, bMax = 0;
    for(int i = 0; i < min(k, n); i++){
        prev += a[i];
        bMax = max(bMax, b[i]);
        maxi = max(maxi, prev + bMax*(k-i-1));
    }
    return maxi;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n, k;
        cin>>n>>k;
        vector<ll> a(n), b(n);
        for(ll i = 0; i < n; i++) cin>>a[i];
        for(ll i = 0; i < n; i++) cin>>b[i];
        cout<<solve(n, k, a, b)<<endl;
    }
    return 0;
}