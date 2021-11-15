#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
    TrieNode* child[2];
    TrieNode(){
        child[0] = NULL;
        child[1] = NULL;
    }

};

void insert(TrieNode* head, int key){
    // every number will be represented as 32 bit 
    // run a loop and extract last bit
    TrieNode* curr = head;
    for(int i=31; i>=0; i--){
        int bit = (key>>i)&1;
        // if bit is 0 then go left ie 0 otherwise right ie 1
        if(bit==0){
            if(curr->child[0]==NULL){
                curr->child[0] = new TrieNode();
            }
            curr = curr->child[0];
        }else{
            if(curr->child[1]==NULL){
                curr->child[1] = new TrieNode();
            }
            curr = curr->child[1];
        }
    }
}

int findMaxXor(TrieNode* head, vector<int> B){
    int max_xor = INT_MIN;
    //check every element of B
    for(int i=0; i<B.size(); i++){
        //evaluate max xor value of B[i] with A
        int curr_xor = 0;
        TrieNode* curr = head;
        for(int j=31; j>=0; j--){
            int bit = (B[i]>>j)&1;
            // if bit is 0 ie we need to go towards 1 if possible because 0^1 = 1
            if(bit==0){
                if(curr->child[1]){
                    curr_xor += pow(2,j);
                    curr = curr->child[1];
                }else{
                    curr = curr->child[0];
                }
            }else{ // bit is 1 ie we need to go towards 0 if possible
                if(curr->child[0]){
                    curr_xor += pow(2,j);
                    curr = curr->child[0];
                }else{
                    curr = curr->child[1];
                }
            }
        }
        max_xor = max(max_xor, curr_xor);
    }
    return max_xor;
}

int main(){
    int N;
    cin>>N;
    vector<int> A(N),B(N);
    for(int i=0; i<N;i++)
        cin>>A[i];
    for(int j=0; j<N; j++)
        cin>>B[j];
    // vector<int> A = {1,2,3}, B = {4,1,2};
    TrieNode* root = new TrieNode(); 
    for(int i=0; i<A.size(); i++)
        insert(root,A[i]);
        
    int res = findMaxXor(root,B);
    cout<<res;
    return 0;
}