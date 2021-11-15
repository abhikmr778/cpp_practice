#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

};

void display(Node* head){
    if(head==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    } 
    cout<<endl;
}

void push(Node* &head, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head=new_node;

}

void insertAfter(Node* &head, int val, int pos){
    if(pos==0 || head==NULL){
        push(head,val);
        return;
    }
    
    Node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }

    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void append(Node* &head, int val){
    if(head==NULL){
        push(head,val);
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    Node* newNode = new Node();
    newNode->data=val;
    newNode->next=NULL;
    temp->next = newNode;

}

void deleteNodewithKey(Node* &head,int key){
    Node* temp = head;
    Node* prev = NULL;

    if(temp!=NULL && temp->data==key){
        //head is to be deleted
        head = temp->next;
        delete temp;
        return;
    }

    while(temp!=NULL && temp->data!=key){
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL) return;

    prev->next = temp->next;
    delete temp;
}

void deleteList(Node* &head){
    Node* current = head;
    Node* temp = NULL;
    while(current!=NULL){
        temp = current->next;
        delete current;
        current = temp;
    }
    head=NULL;
}

int getCount(Node* head){
    //base case
    if(head==NULL) return 0;
    else {
        return 1+getCount(head->next);
    }
}

int getNth(Node* head,int pos){
    
    int count=0;
    while(head!=NULL && count!=pos){
        head=head->next;
        count++;
    }
    return head->data;
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    //allocation
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    display(head);
    push(head,4);
    display(head);
    insertAfter(head,5,1);
    display(head);

    append(head,10);
    display(head);
    cout<<"len= "<<getCount(head)<<endl;
    deleteNodewithKey(head,2);
    display(head);
    cout<<getNth(head, 2);
    // deleteList(head);
    // display(head);
    return 0;
}