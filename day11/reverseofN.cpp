#include <bits/stdc++.h>
using namespace std;
#define int long long

void f(int n){
    if(n>5) return;
    cout<<n<<endl;
    f(n+1);
    return;
}

void solve(){
    f(1);
}
    
int32_t main() {
    
    int t=1;
    while(t--){
        solve();
    }

}