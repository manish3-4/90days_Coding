#include <bits/stdc++.h>
using namespace std;
#define int long long

// void triangle(int n){
//       for (int i = 0; i < n; i++)
//     {
//         for (int j =0; j<n-i-1; j++)
//         {
//             cout <<" ";
//         }
       
//         for(int j=0;j< 2*i+1;j++){
            
//             cout<<"*";
//         }
        
//          for (int j =0; j<n-i-1; j++)
//         {
//             cout <<" ";
//         }
        
//         cout << endl;
//     }
// }
void triangle(int n, int i){
    if(i==n ) return;
    for (int j =0; j<n-i-1; j++)
        {
            cout <<" ";
        }
       
        for(int j=0;j< 2*i+1;j++){
            
            cout<<"*";
        }
        
         for (int j =0; j<n-i-1; j++)
        {
            cout <<" ";
        }
        
        cout << endl;
        triangle(n, i+1);
}

void solve(){
   int n;
   cin>>n;
   triangle(n, 0);
}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}

