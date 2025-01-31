#include <bits/stdc++.h>
using namespace std;
#define int long long

void rev(vector<int> arr, int idx, int n ){
    if(idx == n) return;
    rev(arr,idx+1, n);
    cout<<arr[idx];
}

void solve(){
   vector<int> arr = {1,2,3,4,5,6};
    rev(arr, 0, 6);
}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}

