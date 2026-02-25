#include<bits/stdc++.h>
using namespace std;
using ll = long long;


vector<ll> solve(int n, vector<int> &u, vector<int> &s) {
    vector<vector<int>> skill(n);
    for(int i = 0; i < n; i++) skill[u[i] - 1].push_back(s[i]);

    for(auto &v: skill) sort(v.begin(), v.end());
    vector<vector<long long>> pre(n, vector<long long>(1, 0)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)skill[i].size(); j++) {
            pre[i].push_back(pre[i].back() + skill[i][j]); 
        }
    }

    vector<long long> ans(n + 1);
    for (int i = 0; i < n; i++) {
        int nums = (int)skill[i].size();
        for (int k = 1; k <= nums; k++) {
            ans[k] += pre[i].back() - pre[i][nums % k];
        }
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
        int n;
        cin>>n;
        vector<int> u(n), s(n);
        for(auto &uni: u) cin>>uni;
        for(auto &sk: s) cin>>sk;
        vector<ll> ans = solve(n, u, s);
        for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}