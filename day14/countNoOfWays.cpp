#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(vector<int> arr, int k, int idx, int n){
    if(idx == n){
        if(k ==0){
            return 1;
        }else{
            return 0;
        }
    }
    int ans = 0;
    if(arr[idx] = 1) ans = ans +f(arr, k++, idx+1, n);
    else ans = ans +f(arr, k--, idx+1, n);
    ans = ans +f(arr, k, idx+1, n);
    return ans;

}


void solve(){
int n;
cin>>n;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}    

int ans = f(arr,0, 0, n);
cout<<"No. of ways"<<ans<<endl;

}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}