#include<bits/stdc++.h>
using namespace std;
#define int long long

int lowerBound(vector<int> arr, int n, int ele){
    int st = 0;
    int end = n-1;

    int ans = -1;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(arr[mid]>=ele){
            ans = mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}
int32_t main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ele;
    cin>>ele;

    int ans = lowerBound(arr, n, ele);
    cout<<arr[ans];
}
