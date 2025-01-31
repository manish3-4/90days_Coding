#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* bottom;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->bottom = NULL;
    }
};

void display( Node* root)
{
    while(root->next != NULL){
        while(root->bottom != NULL){
            cout<<root->val<<"->";
            root= root->bottom;
        }
        cout<<endl<<"|";
        cout<<root->val;
        root=root->next;
    }
}



void solve(){
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->next = new Node(8);
    display(head);
}
int32_t main(){
    int t = 1;
    while(t--){
        solve();
    }
}