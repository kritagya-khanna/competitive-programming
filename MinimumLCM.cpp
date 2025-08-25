#include<bits/stdc++.h>
using namespace std;

// long long calculateGCD(long long a, long long b) {
//     while (b != 0) {
//         long long temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

// long long LCM(long long a, long long b){
//     long long gcd = calculateGCD(a, b);
//     return abs(a*b)/gcd;
// }

int main(){
    int T;
    cin>>T;
    while(T--){
        long long n;
        cin>>n;
        // long long a, b;
        // long long mini = LLONG_MAX;
        // for(long long i = 1; i <= n/2; i++){
        //     long long currLcm = LCM(i, n-i);
        //     if(mini > currLcm){
        //         a = i;
        //         b = n - i;
        //         mini = currLcm;
        //     }
        // }
        long long ans_a = 1, ans_b = n-1;
        for(long long i = 2; i*i <= n; i++){
            if(n%i == 0){
                ans_b = n/i;
                ans_a = n - ans_b;
                break;
            }
        }
        cout<<ans_b<<" "<<ans_a<<endl;
    }
    return 0;
}