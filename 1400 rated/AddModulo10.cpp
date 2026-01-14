#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(ll n, vector<ll> &v) {
    bool flag = false;
    for(ll i = 0; i < n; i++){
        if((v[i]%10)%2 != 0) v[i] += (v[i]%10);
        if(v[i] %10 == 0){
            if(flag) return "No";
        }
        else flag = true;
        if(v[i]%10 == 4) v[i] += 18;
        else if(v[i]%10 == 6) v[i] += 6;
        else if(v[i] %10 == 8)  v[i] += 14;
    }
    if(count(v.begin(), v.end(), v[0]) == n) return"Yes";

    for(auto &it: v){
        if(it%10 ==0) return "No";
        it %= 20;
    }
    if(count(v.begin(), v.end(), v[0]) == n) return"Yes";
    else return "No";

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
        vector<ll> v(n);
        for(auto &num: v) cin>>num;
        cout<<solve(n, v)<<endl;
    }
    return 0;
}