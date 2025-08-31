#include<bits/stdc++.h>
using namespace std;

long long solve(long long n,char ch, string s) {
    if(ch == 'g') return 0;
    long long i = 0, j = 0, ans = 0;
    while(s[i] != ch) i++;
    j = i;
    while(i < n){
        while(s[j%n] != 'g'){
            j++;  
        }
        ans = max(ans, j - i);
        i = j+1;
        while(i < n && s[i] != ch) i++;
        j++;
    }
    return ans;
} 

int main(){
    int T;
    cin>>T;
    while(T--){
        long long n;
        cin>>n;
        char ch;
        cin>>ch;
        string s;
        cin>>s;
        cout<<solve(n, ch, s)<<endl;
    }
    return 0;
}