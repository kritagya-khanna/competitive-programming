#include<bits/stdc++.h>
using namespace std;

void helper(long long n, vector<long long> &v, vector<long long> &hash){
    long long cnt = 1;
    for(int i = 1; i < n; i++){
        if(v[i] == v[i-1]) cnt++;
        else{
            hash[v[i-1]] = max(cnt, hash[v[i-1]]);
            cnt = 1;
        }
    }
    hash[v[n-1]] = max(hash[v[n-1]], cnt);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> v1(n), v2(n);
        for(int i = 0; i < n; i++) cin>>v1[i];
        for(int i = 0; i < n; i++) cin>>v2[i];
        vector<long long> hash1(2*n +1, 0);
        vector<long long> hash2(2*n +1, 0);
        helper(n, v1, hash1);
        helper(n, v2, hash2);
        long long ans = 0;
        for(int i = 0; i < 2*n+1; i++){
            ans = max(ans, hash1[i]+hash2[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}