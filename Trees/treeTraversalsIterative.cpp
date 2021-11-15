#include <iostream>
#include <stack>
using namespace std;

class Node{
    public:
    //member contents
    int val;
    Node *left,*right;
    //contructor
    Node(int k){
        val = k;
        left = NULL;
        right = NULL;
    }
};

void inorderIterative(Node* head){
    Node* root = head;
    stack<Node*> s;
    
    while(root!=NULL || s.empty()==false){
        while(root!=NULL){
            s.push(root);
            root = root->left;
        }
        root = s.top(); s.pop();
        cout<<root->val<<" ";
        root = root->right;
    }
    cout<<endl;
}


void preorderTraversal(Node* head){
    stack<Node*> st;
    st.push(head);
    
    while(!st.empty()){
        Node* curr = st.top();
        cout<<curr->val<<" ";
        st.pop();
        if(curr->right!=NULL) st.push(curr->right);
        if(curr->left!=NULL) st.push(curr->left); //we want left to be on top of the stack LIFO
    }

    
    cout<<endl;
}

int main(){
    
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    
    Node* temp = root->left;
    temp->left = new Node(40);
    temp->right = new Node(50);

    temp = root->right;
    temp->left = new Node(60);

    inorderIterative(root);
    preorderTraversal(root);
    return 0;
}