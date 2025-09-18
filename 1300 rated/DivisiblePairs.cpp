#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ll n, x, y;
        cin>>n>>x>>y;
        vector<ll> a(n);
        for(auto &num: a) cin>>num;
       map<ll, vector<ll>> hash;
        for(auto &num: a) hash[num % y].push_back(num);

        ll ans = 0;
        for(auto &it: hash){
            vector<ll> v = it.second;
           map<ll ,ll> hash2;
            for(ll i = 0; i < v.size(); i++) hash2[v[i]%x]++;
            for(auto &itr: hash2){
                if(itr.first == 0 || (itr.first == x/2 && x%2 == 0)){
                    ll cnt = itr.second;
                    ans += (cnt*(cnt - 1))/2;
                    itr.second = 0;
                }
                else {
                    ll cnt1 = itr.second;
                    ll cnt2 = hash2[x - itr.first];
                    ans += (cnt1 * cnt2);
                    hash2[x - itr.first] = 0;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}