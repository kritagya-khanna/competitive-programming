#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool rangeAnd(ll l, ll k, ll mid, vector<vector<ll>> &pre){
    ll ans = 0;
    for(int i = 0; i < 30; i++){
        if(pre[i][mid + 1] - pre[i][l] == 0){
            ans += (1<<i);
        }
    }
    return ans >= k;
}

vector<ll> solve(ll n, ll q, vector<ll> &v, vector<vector<ll>> &quer, vector<vector<ll>> &pre){
    vector<ll> ans;
    for(ll i = 0; i < q; i++){
        ll l = quer[i][0];
        ll k = quer[i][1];
        l--;
        ll low = l, high = n-1;
        if(v[l] < k){
            ans.push_back(-1);
            continue;
        }
        ll temp = -1;
        while(low <= high){
            ll mid = ( low + high ) / 2;
            if(rangeAnd(l, k, mid, pre)){
                temp = mid;
                low = mid + 1; 
            }
            
            else high = mid - 1;
        }
        ans.push_back(temp+1);
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
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(auto &num: v) cin>>num;
        vector<vector<ll>> pre(30, vector<ll>(n + 1, 0));
        for(ll j = 0; j < 30; j++){
            pre[j][0] = 0;
            for(ll i = 0; i < n; i++){
                if((1 << j) & v[i]) pre[j][i + 1] = pre[j][i];
                else pre[j][i + 1] = pre[j][i] + 1;
            }
        }

        ll q;
        cin>>q;
        vector<vector<ll>> quer(q, vector<ll>(2));
        for(auto &qu: quer){
            cin>>qu[0];
            cin>>qu[1];
        }

        vector<ll> ans = solve(n, q, v, quer, pre);
        for(auto it: ans) cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}