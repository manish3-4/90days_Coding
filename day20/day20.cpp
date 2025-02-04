#include<bits/stdc++.h>
using namespace std;

class stack1{
    int top = -1, size;
    vector<int> arr;
    public:
    stack1(int size){
        arr.resize(size);
        this->size = size;
    }
    
    void push(int val){
        if(top == size-1){
            cout<<"FULL"<<endl;
        }else{
            top++;
            arr[top] = val;
        }
    }

    void pop(){
        if(top != -1) cout<<"Underflow"<<endl;
        top--;
    }

    void findtop(){
        if(top!= -1) 
        cout<<arr[top]<<endl;
    }

    bool empty(){
        if(top == -1) return true;
        return false;
    }

};

int main(){
    int n ;
    cin>>n;
    stack1* s = new stack1(n);
    for(int i = 0; i<n; i++){
        s->push(i);
    }
    s->findtop();
    s->pop();
    s->findtop();
    if(s->empty()){
        cout<<"YES, It's Empty"<<endl;
    }else{
        cout<<"No, It's not Empty"<<endl;
    }
    return 0;
}
