#include <iostream>
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
    void insertAtTail(Node* &head,int val)
    {  
    //&head means we are sending original adress of head 
    Node* n=new Node(val);

    if(head == NULL)
    {
        head=n;
        return;
    }

    Node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=n;

    }

    void intsertAtHead(Node*&head,int val)
    {
        Node* n= new Node(val);
        n->next=head;
        head=n;
    }

    bool search(Node*head,int key)
    {
        Node* temp=head;

        while(temp!=NULL)
        {
            if(temp->data == key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    void deletion(Node* &head,int val)
    {
        Node*temp=head;
        if(head==NULL) return;
        while(temp->next->data !=val)
        {
            temp=temp->next;
        }
        Node* del=temp->next;
        temp->next=temp->next->next;
        delete del;

    }

    void delAtHead(Node*&head)
    {
        Node*temp=head;
        head=head->next;
        delete temp;
    }

    void reverse(Node* &head) //Node*  used to return a linked list to a function
    {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while (current != NULL) {
            next = current->next;
            prev = current;
            current = next;
            current->next = prev;
            }
            
            
    }

    Node* revk(Node * &head, int k){
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        int count =0;
        while(k==count){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        return prev;
    }
    

    void display(Node*head)
    {
        Node*temp=head;
        while(temp !=NULL)
        {
            
            cout<<temp->data<<" ->";
            temp=temp->next;
        }
        cout<< "NULL" <<endl;
    }



    int main() {
        
        // Node n1(5);
        Node* head=NULL;
        insertAtTail(head,1);
        insertAtTail(head,2);
        insertAtTail(head,3);
        insertAtTail(head,4);
        insertAtTail(head,5);
        display(head);
        // reverse(head);
        display(head);
        // revk(head, 2);
        // display(head);
        

    }