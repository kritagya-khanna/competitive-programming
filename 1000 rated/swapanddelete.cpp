#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int z =0, o = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == '0') z++;
            else o++;
        }
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                if(z > 0) z--;
                else break;
            }
            else{
                if(o > 0) o--;
                else break;
            }
        }
        cout<<z + o<<endl;

        
    }
    return 0;
}