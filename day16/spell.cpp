// #include<bits/stdc++.h>
// using namespace std;
// int f(vector<int> arr, int idx, map<int, int> mp){
//     int n = arr.size();

//     //base con^
//     if(idx == n) return 0;
//     //not take
//     int take = 0, nottake = 0;
//     nottake += f(arr, idx+1, mp);

//     //take con^
//     take = mp[arr[idx]] * arr[idx];
//     int move = idx+1;
//     while(move<n && (arr[move]-arr[idx]<= 2) ){
//         move++;
//     }
//     take+=f(arr, move, mp);
//     return max(take, nottake);
// }

// void solve(){
//     vector<int> tarr = {7,1,6,3};
//     map<int, int> mp;
//     for(auto it: tarr){
//         mp[it]++;
//     }
//     for(auto it: mp){
//         cout<<it.first<<" "<<it.second<<endl;
//     }
//     int ans = f(tarr, 0, mp);
//     cout<<ans;
// }

// int32_t main(){
//     int t =1;
//     while(t--){
//         solve();
//     }
// }
//leetcode submittion
// class Solution {
//  public:
//   long long maximumTotalDamage(vector<int>& power) {
//   sort(power.begin(), power.end());
//     int n = power.size();
//     vector<long long> dp(n, 0);
//     int prev2 = -1, prev1=0;

//     dp[0] = power[0];

//     for(int i=1; i<n; i++){
//         while(power[prev1] != power[i]) ++prev1;
//         while(prev2 + 1 < i && power[prev2+1] < power[i] -2) ++prev2;

//         if(prev2 == -1){
//             dp[i] = max(dp[i-1], (long long) power[i] * (i-prev1 + 1));
//         }else{
//             dp[i] = max(dp[i-1], dp[prev2] + (long long) power[i] * (i-prev1 + 1));
//         }

//     }
//     return dp[n-1];
//   }
// };


#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int idx, map<int, int>& mp, unordered_map<int, int>& dp) {
    int n = arr.size();

    // Base case
    if (idx == n) return 0;

    // Memoization check
    if (dp.count(idx)) return dp[idx];

    // Not take case
    int nottake = f(arr, idx + 1, mp, dp);

    // Take case
    int take = mp[arr[idx]] * arr[idx];
    int move = idx + 1;
    while (move < n && (arr[move] - arr[idx] <= 2)) { // Fix the condition
        move++;
    }
    take += f(arr, move, mp, dp);

    // Store result in dp
    return dp[idx] = max(take, nottake);
}

void solve() {
    vector<int> tarr = {7,1,3,6};
    map<int, int> mp;
    
    // Count occurrences of each number
    for (auto it : tarr) {
        mp[it]++;
    }

    // Sorting is necessary
    vector<int> arr;
    for (auto it : mp) {
        arr.push_back(it.first);
    }
    sort(arr.begin(), arr.end());

    // Memoization map
    unordered_map<int, int> dp;

    int ans = f(arr, 0, mp, dp);
    cout << ans << endl;
}

int32_t main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
