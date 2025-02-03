#include<bits/stdc++.h>
using namespace std;
int gs(vector<int> arr, int idx, int n, vector<int> temp){

}
int ls(vector<int> arr, int idx, int n, vector<int> temp){

}
int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int g = gs(nums, 0, n, temp);
        int l = ls(nums, 0, n, temp);
        return max(g, l);
}

int main(){
    vector<int> arr = {3,3,3,3};
    int ans = longestMonotonicSubarray(arr);
    cout<<ans;
    return 0;
}