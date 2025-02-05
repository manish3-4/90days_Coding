#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> mp(n);
    for(int i=0; i<n; i++){
        int ct1 = i;
        int ct2 = n-i-1;
        mp[arr[i]] = (ct1+1)*(ct2+1);
    }
    int sum = 0;
    while(n>=0){
        sum += mp[arr[n-1]];
        n--;
    }

    cout<<sum<<endl;
}

