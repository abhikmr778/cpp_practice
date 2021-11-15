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

int diameter(Node* root,int &ans){
    if(root==NULL) return 0;

    int left = diameter(root->left,ans);
    int right = diameter(root->right,ans);

    ans = max(ans,left+right+1);

    return max(left+1,right+1);
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

    int d=0;
    diameter(root,d);
    cout<<d;
    return 0;
}