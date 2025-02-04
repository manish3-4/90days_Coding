#include<bits/stdc++.h>
using namespace std;

int main(){
    string st;
    cin>>st;
    int open = 0;
    for(int i=0; i<st.length(); i++){
        if(st[i] == '(' ){
            open++;
        }
        if(st[i] == ')'){
            open--;
        }
    }

    if(open > 0){
        cout<<"false"<<endl;
    }else{
        cout<<"true"<<endl;
    }
}


