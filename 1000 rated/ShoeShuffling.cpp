#include<bits/stdc++.h>
using namespace std;
vector<long long> solve(long long n, vector<long long> &s){
    if(n==1) return {-1};
    long long j = 0;
    vector<long long> ans(n);
    for(long long i = 0; i < n; i++){
        if(s[i] != s[i+1] || i == n-1){
            if(i == j) return {-1};
            ans[j] = i + 1;
            j++;
            while(j <= i){
                ans[j] = j; 
                j++;
            }
        }
    }
    if(s[n-1] != s[n-2]) return {-1};
    return ans;

}
int main(){
    int T;
    cin>>T;
    while(T--){
        long long n;
        cin>>n;
        vector<long long> s(n);
        for(int i = 0; i < n; i++) cin>>s[i];
        vector<long long> ans;
        ans = solve(n, s);
        for(int i = 0 ;i < ans.size(); i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}