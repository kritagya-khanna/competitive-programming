#include<bits/stdc++.h>
using namespace std;
long long solve(long long n, long long k, vector<long long> &v){
    long long cnt = 0, ans = 0;
    for(long long i = 0; i < n; i++){
        if(v[i] == 1)cnt++;
        else{
            if(cnt>=k){
                long long num = cnt-k+1;
                ans += (num)*(num+1)/2;
            }
            cnt = 0;
        }
    }
    if(cnt>=k){
        long long num = cnt-k+1;
        ans += (num)*(num+1)/2;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, k, q;
        cin>>n>>k>>q;
        vector<long long> v(n);
        for(long long i = 0; i < n; i++){
            long long a;
            cin>>a;
            if(a <= q) v[i] = 1;
            else v[i] = 0;
        }
        cout<<solve(n, k, v)<<endl;
    }
    return 0;
}