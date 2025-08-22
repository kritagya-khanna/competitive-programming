#include<bits/stdc++.h>
using namespace std;

long long solve(int n, vector<vector<int>> &v){
    if(n == 1) return v[0][0];
    sort(v.begin(), v.end(), [](vector<int>&a, vector<int>&b){return a[1] < b[1];});
    long long ans = 0, mini = LLONG_MAX;
    for(int i = 1; i < n; i++){
        ans+=v[i][1];
        mini = min(1ll*v[i][0], mini);
    }
    mini = min(mini, 1ll*v[0][1]);
    mini = min(mini, 1ll*v[0][0]);
    ans+= mini;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> v(n);
        for(int i = 0; i < n; i++){
            int m;
            cin>>m;
            vector<int> temp(m);
            for(int j = 0; j < m; j++) cin>>temp[j];
            sort(temp.begin(), temp.end());
            v[i] = temp;
        }
        cout<<solve(n, v)<<endl;
    }
    return 0;
}