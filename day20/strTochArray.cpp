#include <bits/stdc++.h>
using namespace std;

int main(){
    string st = "Manish";

    int n = st.length();

    char arr[n];

    strcpy(arr, st.c_str());

    for(auto it:arr){
        cout<<it<<endl;
    }
}