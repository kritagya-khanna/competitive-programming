#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(ll n, ll x, ll y, vector<ll> &v) {
    ll alice = x, bob = x + 3;
    ll oddCnt = 0;
    for(auto num: v) if(num%2) oddCnt++;
    int aliceStart = x % 2, bobStart = 1 - aliceStart;
    int aliceEnd, bobEnd;
    if(oddCnt % 2 == 0) {
        aliceEnd = aliceStart;
        bobEnd = bobStart;
    }
    else {
        aliceEnd = 1 - aliceStart;
        bobEnd = 1 - bobStart;
    }
    return aliceEnd == y % 2 ? "Alice": "Bob";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ll n, x, y;
        cin>>n>>x>>y;
        vector<ll> v(n);
        for(auto &num: v) cin>>num;
        cout<<solve(n, x, y, v)<<endl;
    }
    return 0;
}