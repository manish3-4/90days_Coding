#include <bits/stdc++.h>
using namespace std;
#define int long long

bool stringpdr(string &s, int left, int right){
    if(left>=right) return true;
    if(s[left] != s[right]) return false;
    return stringpdr(s, left+1, right-1);
}

void stringpalindrom(string s){
    if(stringpdr(s, 0, s.size()-1)){
        cout<<"pdr";
    }else{
        cout<<"notpdrm";
    }
    
}

void solve(){
    string str;
    cin>>str;
    stringpalindrom(str);
}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}

