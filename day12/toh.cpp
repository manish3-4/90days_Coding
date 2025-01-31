#include <bits/stdc++.h>
using namespace std;
#define int long long

void towerOfHanoi(int n, string src, string helper, string dest) {
        if (n == 1) { 
            cout<<"transfer disk " << n << " from " << src << " to " << dest<<endl;
            return;
        }
        towerOfHanoi(n-1, helper, src, dest); 
        cout<<"transfer disk* " << n << " from " << src << " to " << dest<<endl; 
        towerOfHanoi(n-1, src, dest, helper); 
}

   

void solve(){
    int n = 4; 
    towerOfHanoi(n, "A", "B", "C");
}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}

