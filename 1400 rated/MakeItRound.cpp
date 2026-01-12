#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> p2(19), p5(19);

ll solve(ll n, ll m) {
    ll temp = n;
    int pow2 = 0, pow5 = 0;

    while(temp){
        if(temp%2 == 0) pow2++;
        else break;
        temp/=2;
    }

    temp = n;
    while(temp) {
        if(temp%5 == 0) pow5++;
        else break;
        temp/=5;
    }

    for(int i = 18; i >= 1; i--){

        int no2 = max(0, i - pow2);
        int no5 = max(0, i - pow5);

        if(p5[no5] * p2[no2] <= m){
            ll maxi = m - m%(p2[no2]*p5[no5]);
            return maxi*n;
        }
    }

    return n*m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ll n,m;
        cin>>n>>m;
        p2[0] = 1;
        p5[0] = 1;
        for(int i = 1; i <= 18; i++) {
            p2[i] = (p2[i-1]*2);
            p5[i] = (p5[i-1]*5);
        }
        cout<<solve(n, m)<<endl;
    }
    return 0;
}