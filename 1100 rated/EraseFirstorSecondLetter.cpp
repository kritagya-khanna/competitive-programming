#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, string s){
    unordered_set<char> st;
    ll cnt = 0;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(st.find(s[i]) == st.end()){
            cnt++;
            st.insert(s[i]);
        }
        ans += cnt;
    }
    return ans;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(n, s)<<endl;
    }
    return 0;
}