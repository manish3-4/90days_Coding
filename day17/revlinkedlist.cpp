#include<bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}


// while(curr!= NULL){
//     Node* next/front = curr->next;
//     curr->next = prev;
//     prev = curr;
//     curr = next;
// }
// return prev;

// written by me--->
// if(curr == NULL) return prev;

// curr->next = prev;

// prev = curr;

// curr = next;
// f(head, curr, prev);


// written by sir ---->
// Node* f(head){
// if(head == NULL) return head;
// if(head->next == NULL) return head;

// Node* revhead = f(head->next);
// Node* nnode = head->next;
// nnode->next = head;
// head->next = NULL;
// return revhead;
// }

//detect loop---->
// Node* slow/fast = head;

// while(fast != NULL && fast != ){
//     slow = slow->next;
//     fast = fast->next->next;
//     if(slow == fast){
            // slow = head;
            // while(slow!= fast){
            //     slow = slow->next;
            //     fast = fast->next;
            // }
            // return fast;
            // }
// }
// return false;


//collision point---->



