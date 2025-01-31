#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum(vector<int> arr, int n){
    if(n<0) return 0;
    int s = sum(arr, n-1)+arr[n];
    return s;
}

    
int32_t main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int s = 0;
    s= sum(arr, n-1);
    cout<<s;
}