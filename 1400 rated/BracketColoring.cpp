#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> temp;
int solve(ll n, string &s){
    vector<ll> ans;
    ll bal = 0;
    bool prev = true, neg = false, pos = false;
    for(auto ch: s){
        if(ch == '(') bal++;
        else bal--;
        if(bal > 0){
            ans.push_back(1);
            prev = true;
            pos = true;
        }
        else if(bal < 0){
            ans.push_back(2);
            prev = false;
            neg = true;
        }
        else{
            if(prev) ans.push_back(1);
            else ans.push_back(2);
        }
    }
    if(neg && !pos){
        for(auto &num: ans) num = 1;
    }
    temp = ans;
    if(bal != 0) return -1;
    if(neg && pos) return 2;
    return 1;
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
        string s;
        cin>>s;
        int num = solve(n, s);
        cout<<num<<endl;
        if(num!=-1){
            for(auto num: temp) cout<<num<<" ";
            cout<<endl;
        }
    }
    return 0;
}