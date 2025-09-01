#include<bits/stdc++.h>
using namespace std;

long long solve(long long n, long long d, vector<long long> &v){
    sort(v.begin(), v.end());
    long long i = 0, j = n-1;
    long long cnt = 0;
    while(i <= j){
        long long players = d/v[j];
        players+=1;
        i+=(players-1);
        if(i > j) return cnt;
        j--;
        cnt++;
    }
    return cnt;
}

int main(){
    long long n, d;
    cin>>n>>d;
    vector<long long> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    cout<<solve(n, d, v);
    return 0;
}