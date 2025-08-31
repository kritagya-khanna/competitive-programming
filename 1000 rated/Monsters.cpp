#include<bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(const pair<long long,long long>& a, const pair<long long,long long>& b) const {
        if (a.first == b.first) 
            return a.second < b.second; 
        return a.first > b.first;      
    }
};
// void solve(long long n, long long k, vector<long long> &v, vector<int> &ans){
//     priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, Compare> pq;
//     for(long long i = 0; i < n; i++) {
//         pq.push({v[i], i});
//     }
//     while(!pq.empty()){
//         long long health = pq.top().first;
//         int index = pq.top().second;
//         pq.pop();
//         health -= k;
//         if(health <= 0){
//             ans.push_back(index+1);
//         }
//         else pq.push({health, index});
//     }
// }
void solve(long long n, long long k, vector<long long> &v, vector<int> &ans){
    vector<pair<long long, long long>> temp;
    for(int i = 0; i < n; i++){
        v[i] = (v[i] % k);
        if(v[i] == 0) ans.push_back(i+1);
        else temp.push_back({v[i], i});
    }
    sort(temp.begin(), temp.end(), Compare());
    for(int i = 0; i < temp.size(); i++){
        ans.push_back(temp[i].second + 1);
    }

}
int main(){
    int T;
    cin>>T;
    while(T--){
        long long n, k;
        cin>>n>>k;
        vector<long long> v(n);
        for(int i = 0; i < n; i++) cin>>v[i];
        vector<int> ans;
        solve(n, k, v, ans);
        for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
        cout<<endl;
    } 
}