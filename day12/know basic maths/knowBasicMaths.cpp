#include <bits/stdc++.h>
using namespace std;
#define int long long

void count(int n){
    cout<<log10(n)+1<<endl;
}

 int evenlyDivides(int n) {
        // code here
        int temp = n;
        int count = 0;
        while(n>0){
            int r = n%10;
            if(temp%r == 0){
                count++;
            }
            n/=10;

            cout<<"temp: "<<temp<<" remainder: "<<r<<" count: "<<count<<" number: "<<n<<endl;
        }
        return count;
    }

int rev(int n){
   
        int ans = 0;
        while (n != 0) {
            int q = n % 10;
            if (ans > (INT_MAX / 10) || (ans == INT_MAX / 10 && q > 10)) {
                return 0;
            }
            if (ans < (INT_MIN / 10) || (ans == INT_MIN / 10 && q < -10)) {
                return 0;
            }
            ans = ans * 10 + q;
            n /= 10;
        }
        return ans;
}

void solve(){
    int n;
    cin>>n;
//    count(10);
//    evenlyDivides(n);
    cout<< rev(n);
}
    
int32_t main() {
    int t=1;
    while(t--){
        solve();
    }

}

