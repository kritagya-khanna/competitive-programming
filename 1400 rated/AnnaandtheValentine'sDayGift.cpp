#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(ll n, ll m, vector<ll> &v){
    ll totalDigit = 0;
    vector<ll> trailing(n);
    for(ll i = 0; i < n; i++){
        while(v[i] % 10 == 0){
            trailing[i]++;
            v[i] /= 10;
        }
        while(v[i] != 0){
            totalDigit++;
            v[i] /= 10;
        }
    }

    sort(trailing.rbegin(), trailing.rend());
    for(int i = 1; i  <n; i+=2){
        if(trailing[i] == 0) break;
        totalDigit += trailing[i];
    }
    return totalDigit > m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ll n, m;
        cin>>n>>m;
        vector<ll> v(n);
        for(auto &num: v) cin>>num;
        cout<< (solve(n, m, v) ? "Sasha" : "Anna")<<endl;;
    }
    return 0;
}