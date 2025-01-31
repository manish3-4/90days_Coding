#include <bits/stdc++.h>
using namespace std;
#define int long long

void patt(int n){
    if(n<1) return;
    patt(n-1);
    int i =0;
    while(i<n){
        cout<<"*"<<" ";
    }
    cout<<endl;
    return;
}

void solve(){
    patt(5);
}
    
int32_t main() {
    
    int t=1;
    while(t--){
        solve();
    }

}