#include <bits/stdc++.h>
using namespace std;

vector<int> celeb(vector<int> arr, int k){
   int ft, mid, end;
   int st = k-1;
   int n = arr.size();
   vector<int> temp(n, 0);
    while(st<n){
        end = arr[st];
        mid = arr[st-1];
        ft = arr[st-2];
        temp.push_back(max(ft, mid, end));
        st++;
    }
    return temp;
}

int main()
{
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = celeb(arr, k);
    for(auto it:ans){
        cout<<it<<" ";
    }
}


























