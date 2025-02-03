// //intersecting point of two linkedlist
// #include<bits/stdc++.h>
// using namespace std;

// class Node{
//     int val;
//     Node* next;
//     Node(int val){
//         this->val = val;
//         this->next = NULL;
//     }
// };

// int main(){
//     Node* head = NULL;

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n->next=head;
    head = n;
}

void insertAtPos(Node* &head, int val, int k){
    Node* temp = head;
    int n=1;
    while(k-1 != n){
        ++n;
        temp=temp->next;
    }
    
    Node* nextnode = new Node(val);
    nextnode->next = temp->next;
    temp->next = nextnode;

}

void deleteAtPos(Node* &head, int k){
    Node* temp = head;
    int n=1;
    while(k-1 != n){
        ++n;
        temp=temp->next;
    }
    
    temp->next = temp->next->next;

}

int removeMiddle(Node* temp){
    Node* slow = temp;
    Node* fast = temp;
    int count = 1;
    while(fast!= NULL && fast->next!=NULL && fast->next->next!= NULL){
        count++;
        slow = slow->next;
        fast=fast->next->next;
    }
    return count;
}

Node * intersection(Node* h1, Node* h2){
    Node* temp1 = h1;
    Node* temp2 = h2;

    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == NULL) temp1 = h2;
        if(temp2 == NULL) temp2 = h1;
    }
    if(temp1 == temp2){
        return temp1;
    }else{
        return NULL;
    }
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
        cout<<"NULL"<<endl;
}

void solve(){
    Node* head = NULL;
    vector<int> arr = {1,2, 3, 4, 5, 6};
    for(int i=0; i<arr.size(); i++){
        insertAtHead(head, arr[i]);
    }
    display(head);
    int k = 2;
    int val = 7;
    insertAtPos(head, val, k);
    display(head);
    deleteAtPos(head, 3);
    display(head);
    int mid = removeMiddle(head);
    cout<<mid<<endl;

    
}

int32_t main(){
    int t =1;
    while(t--){
        solve();
    }
}

// //---->
// Node* head = f(arr);
// Node* temp = head;
// while( temp != NULL){
//     cout<<temp->var;
//     temp= temp-> next;
// }