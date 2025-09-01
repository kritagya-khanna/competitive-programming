#include <bits/stdc++.h>
using namespace std;

long long solve(long long n, long long x, vector<long long> &v) {
    pair<long long, long long> prev = {LLONG_MIN, LLONG_MAX};
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        long long minVal = v[i] - x;
        long long maxVal = v[i] + x;

        if (max(prev.first, minVal) <= min(prev.second, maxVal)) {
            prev.first = max(prev.first, minVal);
            prev.second = min(prev.second, maxVal);
        } else {
            prev = {minVal, maxVal};
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, x;
        cin >> n >> x;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(n, x, v) << endl;
    }
    return 0;
}
