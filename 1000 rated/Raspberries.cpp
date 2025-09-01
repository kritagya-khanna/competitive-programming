#include<bits/stdc++.h>
using namespace std;

long long raspberries(vector<long long> &v, int k){
    int n = v.size();
    long long mini = LLONG_MIN;
    int evenCnt = 0;
    for(int i = 0; i < n; i++){
        if(v[i] % k == 0) return 0;
        if(v[i] % 2 == 0) evenCnt++;
        mini = max(mini, v[i] % k);
    }
    if(k == 4){
        if(evenCnt > 1) return 0;
        return min(k - mini, 1ll*(2 - evenCnt));
    }
    return k - mini;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,  k;
        cin>>n>>k;
        vector<long long> v(n);
        for(int i = 0; i < n; i++) cin>>v[i];
        cout<<raspberries(v, k)<<endl;
    } 
    return 0;
}