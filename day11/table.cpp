#include <bits/stdc++.h>
using namespace std;
#define int long long
void table(int n, int i){
if(i>n) return;
cout<<n<<"X"<<i<<"="<<n*i<<endl;
table(n, i+1);
}
    
int32_t main() {
    int n=10;
    int i=1;
    table(n, i);
}