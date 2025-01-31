#include <bits/stdc++.h>
using namespace std;
#define int long long

bool f(vector<int> arr, int n, int k){
    if(k==0){
        return true;
    }
}


void solve(){
    vector<int> arr = {1,0,1,1,0,1};
    int n=arr.size()-1;
    int k = 1;
    if(f(arr, n, k)){
        cout<<"found";
    }else{
        cout<<"NotFound";
    }
}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}

