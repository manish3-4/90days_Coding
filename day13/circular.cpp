#include <bits/stdc++.h>
    using namespace std;
    class Node{
        public:  //default access specifier is private,
        int data;
        Node*next;

        Node(int val)
        {
            data=val;
            next=NULL;
        }
    };
    
    void insertAtHead(Node* &head, int data){
        Node* n = new Node(data);
        Node* temp = head;
        if(head == NULL){
            n->next = n;
            head = n;
            return;
        }
        while (temp->next != head)
        {
            /* code */
            temp = temp->next;
        }
        temp->next = n;
        n->next=head;
        head = n;
        cout<<"Node Inserted At Head"<<data<<endl;
    }

    void insertAtTail(Node* &head, int data){
        Node* n = new Node(data);
        Node* temp = head;
        if(head->next == NULL){
            insertAtHead(head,data);
            return;
        }
        while (temp->next != head)
        {
            /* code */
            temp = temp->next;
        }
        temp->next = n;
        n=head;
    }

    void deletionAtHead(Node* &head){
        Node* temp = head;
        Node* del = head;
        while(temp->next == head){
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next; 
        delete del; 
    }
    

    void display(Node* head)
    {
        Node*temp=head;
        while(temp->next!= head)
        {
            
            cout<<temp->data<<" ->";
            temp=temp->next;
        }
        cout<<"Done"<<endl;
    }

    Node* circularchk(Node* &head){ //floyd detecton loop
        if(head == NULL){
            return NULL;
        }
        Node* slow=head;
        Node* fast=head;
        
        while(fast != NULL){
            slow = slow->next;
            fast= fast->next->next;
            if(fast == slow){
                return slow;
            }
        }
        return NULL;
    }

    Node* getStartingNode(Node* head){
        if(head == NULL) return NULL;
        Node* intersection = circularchk(head);
        Node* slow = head;

        while(slow != intersection){
            slow = slow->next;
            intersection = intersection->next;
        }
    }

    Node* removeloop(Node* head){
        if(head == NULL) return NULL;
        Node* startofLoop = getStartingNode(head);
        Node* temp = startofLoop;

        while (temp->next != startofLoop)
        {
            /* code */
            temp=temp->next;
        }
        temp->next=NULL;
    }

    int main() {
        
        Node n1(5);
        Node* head=NULL;
        cout<<"displaying======>"<<endl;
        display(head);
        cout<<"Inserting =====>"<<endl;
        insertAtTail(head, 1);
        insertAtTail(head, 2);
        insertAtTail(head, 3);
        cout<<"displaying======>"<<endl;
        display(head);
       
        

    }