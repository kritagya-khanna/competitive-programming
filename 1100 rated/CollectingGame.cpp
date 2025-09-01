#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> solve(ll n, vector<pair<ll, ll>> &v) {
    vector<ll> ans(n);
    sort(v.begin(), v.end());
    ll i = 0, j = 0;
    ll sum = 0;

    while (i < n) {
        if (sum >= v[i].first) {
            sum += v[i].first;
            i++;
        } else {
            while (j < i) {
                ans[v[j].second] = i-1;
                j++;
            }
            sum += v[i].first;
            i++;
        }
    }

    while (j < n) {
        ans[v[j].second] = i-1;
        j++;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> v(n);
        for (ll i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            v[i] = {temp, i};
        }
        vector<ll> ans = solve(n, v);
        for (int x : ans) cout << x << " ";
        cout <<endl;
    }
    return 0;
}
