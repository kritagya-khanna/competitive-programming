#include<bits/stdc++.h>
using namespace std;

vector<long long> solve(long long n, long long k, long long b, long long s){
    long long minS = b * k, maxS = b * k + n*(k-1);
    if(s < minS || s > maxS) return {-1}; 
    vector<long long> ans(n, 0);
    s -= b*k;
    ans[0] = b*k;
    for(int i = 0; i < n; i++){
        if(s == 0) break;
        if(s >= k - 1){
            ans[i] += (k-1);
            s -= (k-1);
        }
        else{
            ans[i] += s;
            s = 0;
        }
        
    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        long long n, k, b, s;
        cin>>n>>k>>b>>s;
        vector<long long> ans;
        ans = solve(n, k, b, s);
        for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}