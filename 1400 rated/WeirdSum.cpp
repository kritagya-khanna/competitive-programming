#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll MAX_COLORS = 100001;

ll calculate(vector<int> &a) {
    sort(a.begin(), a.end(), greater<>());
    ll size = a.size();
    ll sum = 0;
    for(ll i = 0, j = size - 1; i < size; i++, j -= 2) {
        sum += (1ll * j * a[i]);
    }

    return sum;
}

ll solve(ll n, ll m, vector<vector<int>> &v) {
    vector<vector<int>> x(MAX_COLORS), y(MAX_COLORS);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            x[v[i][j]].push_back(i);
            y[v[i][j]].push_back(j);
        }
    }

    ll ans = 0;
    for(ll i = 0; i < MAX_COLORS; i++) {
        ans += calculate(x[i]);
        ans += calculate(y[i]);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int T;
    // cin>>T;
    // while(T--){
        ll n, m;
        cin>>n>>m;
        vector<vector<int>> v(n, vector<int>(m));
        for(auto &vec: v){
            for(auto &num: vec) {
                cin>>num;
                num--;
            }
        }
        cout<<solve(n, m, v)<<endl;
    // }
    return 0;
}