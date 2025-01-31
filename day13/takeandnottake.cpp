#include <bits/stdc++.h>
using namespace std;
#define int long long

// vector<vector<int>> ans;

// void subseq(vector<int> arr,int idx, int k,vector<int> temp){
//     if(idx == arr.size()){
//             int sum = 0;
//         for(auto it: temp){
//             sum+=it;
//         cout<<"sum ->"<<sum<<endl;

//         }
//         if(sum == k){
//             ans.push_back(temp);
//             for(auto ans: ans){
//             }
//         }
//         return;
//     }
//     temp.push_back(arr[idx]);
//     for(auto it: temp){
//         cout<<"PUSHED ->"<<it<<endl;
//     }
//     subseq(arr, idx+1, k, temp);
//     temp.pop_back();
    
//     for(auto it: temp){
//         cout<<"POPED ->"<<it<<endl;
//     }
//     subseq(arr, idx+1, k, temp);

// }
// int sum = 0;
// vector<vector<int>> ans;

//  void coinch(vector<int> arr, int k, int idx){
//     if(sum == k){
//         cout<<"done"<<endl;
//     }
    
//     //take
//     if(arr[idx] <= k)
//     coinch(arr, k-arr[idx], idx);
//     //not take
//     coinch(arr, k, idx+1);

//  }

int f(vector<int> arr, int k, int idx, int n){
    if(idx == n){
        if(k ==0){
            return 1;
        }else{
            return 0;
        }
    }
    int ans = 0;
    if(k-arr[idx] >= 0) ans = ans +f(arr, k-arr[idx], idx+1, n);

    ans = ans +f(arr, k, idx+1, n);
    return ans;

}

void solve(){
    // int k, n;
    // cin>>n;
    // vector<int> arr(n);
    // for(int i = 0; i<n; i++){
    //     cin>>arr[i];
    // }
    // cin>>k;//sum

    // coinch(arr, k, 0);
    int n ;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans = f(arr, k, 0, n);
    cout<<ans<<endl;

}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}

