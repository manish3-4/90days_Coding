#include <bits/stdc++.h>
using namespace std;
#define int long long

void toh(int n, string src, string helper, string des){
    if(n == 0) return;
    toh(n-1, src, des, helper);
    cout<<"put "<<src<<"to"<<des<<endl;
    toh(n-1, helper, src, des);
}

void maxsizepal(vector<int> arr, int n, int st, int end, int ans){
    
    int mid = st+(end-st)/2;
    if(arr[st] == arr[end]){
        ans+=2;
    }if(arr[st]>arr[end]){

    }
}


//largest palindromic array gfg
vector<vector<int>> ans;


void subseq(vector<int> arr,int idx, int k,vector<int> temp){
    if(idx == arr.size()){
            int sum = 0;
        for(auto it: temp){
            sum+=it;
        }
        if(sum == k){
            ans.push_back(temp);
            return;
        }
    }
    temp.push_back(arr[idx]);
    subseq(arr, idx+1, k, temp);
    temp.pop_back();
    subseq(arr, idx+1, k, temp);

}



   

void solve(){
    // int n;
    // cin>>n; 
    // // toh(n, "A", "B", "C");
    // vector<int> arr;
    // for(int i = 0; i<n; i++){
    //     cin>>arr[i];
    // }
    // int st, end;
    // st = 0;
    // end = arr.size()-1;
    // int ans = 0;
    // maxsizepal(arr, n, st, end, ans);   
    int k, n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cin>>k;

    vector<int> temp;
    vector<vector<int>> ans;

    subseq(arr, 0, k, temp);

}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}

