#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n;
    cin>>n;
    int query, val;
    set<int> s;
    for(int i=0;i<n; i++){
        cin>>query>>val;
        s.insert(query);
        auto lower = s.lower_bound(val);
        auto upper = s.upper_bound(val);
        cout<<*lower<<" "<<*upper;
        s.clear();
    }
}