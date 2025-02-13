#include<bits/stdc++.h>
using namespace std;
void f(vector<int> &arr, int k=10){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    while((n--) > 2){
        arr.pop_back();
    }
    arr.push_back(15);
}

int main() {
    vector<int> arr = {3,2,1,11};
    f(arr);
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}