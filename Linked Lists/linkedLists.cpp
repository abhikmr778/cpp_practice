#include <iostream>
using namespace std;

// struct Node{
//     int data;
//     struct Node* link;
// };

class Node{
    public:
    int data;
    Node* next; //it is of type Node* as it is pointing to a Node datatype and it is a pointer

    Node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(Node* &head,int val){//taking head by reference as we want to modify the list
    
    Node* n = new Node(val);//make a new node to insert
    
    if(head==NULL){
        head=n;
        return;
    }

    
    Node* temp = head;//iterator to get to the end
    while(temp->next!=NULL){//takes us to the last element
        temp = temp->next;
    }

    temp->next=n;//make last element point to new node created
}

void insertAtHead(Node* &head,int val){
    Node* n=new Node(val);
    n->next=head;
    head=n;
}

void display(Node* head){//by value as we dont want to modify
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(Node* head,int key){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==key) return true;
        temp=temp->next;
    }
    return false;
}

int main(){
    Node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    display(head);
    cout<<search(head,4);
    return 0;
}