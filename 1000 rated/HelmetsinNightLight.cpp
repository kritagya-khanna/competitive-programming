#include <bits/stdc++.h>
using namespace std;

long long solve(vector<pair<int, int>> &v, int p){
    int n = v.size();
    long long cost = 0;
    int left = n;
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        if(left <= 0) break;
        if(v[i].first >= p) break;
        int take = min(v[i].second, left - 1);
        cost += 1LL * take * v[i].first;
        left -= take;
    }
    cost += 1LL * left * p;

    return cost;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, p;
        cin >> n >> p;
        vector<pair<int, int>> v(n);

        for(int i = 0; i < n; i++) cin >> v[i].second;
        for(int i = 0; i < n; i++) cin >> v[i].first;

        cout << solve(v, p) << "\n";
    }
    return 0;
}
