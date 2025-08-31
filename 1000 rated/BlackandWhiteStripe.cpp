#include<bits/stdc++.h>
using namespace std;

long long solve(long long n, long long k, string s){
    long long mini = LLONG_MAX;
    if(n < k) return mini;
    long long whiteCnt = 0;
    long long i = 0, j = 0;
    while(i < n && j < n) {
        if(s[i] == 'W') whiteCnt++;
        if(i - j + 1 == k){
            mini = min(whiteCnt, mini);
            if(s[j] == 'W') whiteCnt--;
            j++;
        }
        i++;
    }
    return mini;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        long long n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        cout<<solve(n, k, s)<<endl;
    }
    return 0;
}