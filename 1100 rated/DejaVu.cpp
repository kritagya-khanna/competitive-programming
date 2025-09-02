#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ll n, q;
        cin>>n>>q;
        vector<ll> a(n), x(q);
        for(ll i = 0; i < n; i++) cin>>a[i];
        for(ll i = 0; i < q; i++) cin>>x[i];
        ll prev = 31;
        for(ll i = 0; i < q; i++){
            if(x[i] >= prev) continue;
            ll val = pow(2, x[i]);
            for(auto &num : a){
                if(num%val == 0){
                    num += (val/2);
                }
            }
            prev = x[i];
        }
        for(ll i = 0; i < n; i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}