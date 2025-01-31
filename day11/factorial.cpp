#include <bits/stdc++.h>
using namespace std;
#define int long long
int fac(int n){
if(n==1) return 1;
int ans = fac(n-1)*n;
return ans;
}
    
int32_t main() {
    int n;
    cin>>n;
    int ans = fac(n);
    cout<<ans<<endl;
}