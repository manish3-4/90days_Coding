#include <bits/stdc++.h>
using namespace std;
#define int long long

int fab(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    int ans = fab(n-1)+fab(n-2);
    return ans;

    
}

void solve(){
   int ans = fab(5);
   cout<<ans<<endl;
}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}

// int f(int n){
// //base condition---
// if(n==1) return 0;
// if(n==2) return 1;
// //calling the function
// int prevFib=f(n-1);
// int prevToprevFib=f(n-2);
// int ans=prevFib+prevToprevFib;
// return ans;
// }