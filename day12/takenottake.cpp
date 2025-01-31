#include <bits/stdc++.h>
using namespace std;
#define int long long
void f(vector<int> arr, int idx, vector<vector<int>> ans, vector<int> temp){
    if(idx == arr.size()){
        for(int i=0; i<temp.size(); i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[idx]);
    f(arr, idx+1, ans, temp);
    //don't take
    temp.pop_back();
    f(arr, idx+1, ans, temp);
}

void solve(){
    vector<int> arr = {1,2,3};
    vector<int> temp;
    vector<vector<int>> ans;

    f(arr, 0, ans, temp);
}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}

