#include <bits/stdc++.h>
using namespace std;
#define int long long


// int f(vector<int> arr, int idx, int n){
//     if(n<0) return 0;
//     if(n == 0){
//         return 1;
//     }
//     int ans = 0;
//      ans += f(arr,idx+1, n-1);
//      ans += f(arr,idx+2, n-2);
//     return ans;
// }
// int f(int n){
//     if(n<=2) return n;
//     int ans = 0;
//     ans += f(n-1);
//     ans += f(n-2);
//     return ans;
// }
int dice(int n){ //n is the sum
    if(n<0) return 0;
    if(n==0) return 1;
    int ans = 0;
    for(int i=0; i<6; i++){
        ans+=dice(n-i);
    }
    return ans;
}
int prime(vector<int> arr, int idx, int n){
    if(n<0) return 0;
    if(idx == n) return 1;
    int ans = 0;
    ans += prime(arr, idx, n-1);
    ans += prime(arr, idx+1, n-1);
    return ans;
}
int composite(vector<int> arr, int idx, int n){
    if(n<0) return 0;
    if(idx == n) return 1;
    int ans = 0;
    ans += composite(arr, idx, n-1);
    ans += composite(arr, idx+1, n-1);
    return ans;
}

int number(int n){
    // if(n==0) return 1;
    // if(n<0) return 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(i%2 == 0){
            // vector<int> primee = {2,3,5,7};
            // int n= primee.size();
            ans *= 4;
            // prime(primee, 0, n);
        }else{
            vector<int> compositee = {0,1,4,6,8,9};
            int n= compositee.size();
            ans *= composite(compositee, 0, n);
        }
    }
    return ans;
}

// int f(vector<int> arr, int idx, int k){
//     if (k<0) return 0;
//    if(idx < arr.size()){
//     if(k==0) return 1;
//    }
//     int ans=0;
//     if(arr[idx]>=0)ans+=f(arr, idx, k-arr[idx]);
//     ans+=f(arr, idx+1, k);
//    return ans;
// }


void solve(){
// vector<int> arr(n);
// for(int i = n; i>-1; i--){
//     arr[n-i] = i;
// }    
// int ans = f(arr, 0, n);
// int ans = f(n);
int n;
cin>>n;
// vector<int> arr ={1,2,3,4,5,6};
// int ans = f(arr, 0, n);
// int ans = dice(n);
int ans = number(n);
cout<<"No. of ways-> "<<ans<<endl;

}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}
// code written by sir---->
// f(n, 0, p, c){
//     if(n == idx) return 1;

//     int ans =0;
//     if(idx%2 == 0){
//         for i in prime{
//             ans += f(n, idx+1, p, c);
//         }
//     }else{
//         for i in composite{
//             ans += f(n, idx+1, p, c);
//         }
//     }
//     return ans;
// }