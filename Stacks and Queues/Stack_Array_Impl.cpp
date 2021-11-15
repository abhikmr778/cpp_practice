//For stack using arrays we need
// - push function
// - top function
// - pop function
// - isEmpty function


#include <iostream>

using namespace std;

#define max_size 10

int A[max_size];
int top=-1;

bool isEmpty(int top){
    if(top==-1) return true;
    else return false;
}

void push(int *A, int val, int top){
    if(top==max_size){
        cout<<"Stack Full"<<endl;
        return;
    }
    A[++top] = val; 
}

void pop(int *A, int top)

int main(){
    push(A,1,top);

    return 0;
}