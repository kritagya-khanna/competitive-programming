#include<bits/stdc++.h>
using namespace std;
long long solve(long long n, string s){
    vector<long long> prefix(n, 0);
    unordered_set<char> st;
    for(long long i = 0; i < n; i++){
        st.insert(s[i]);
        prefix[i] = st.size();
    }
    st.clear();
    long long ans = 0;
    for(long long i = n-1; i >= 1; i--){
        st.insert(s[i]);
        ans = max(ans, prefix[i-1] + (long long)st.size());
    }
    return ans;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        long long n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(n, s)<<endl;
    }
    return 0;
}