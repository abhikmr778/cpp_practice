#include <iostream>
#include <cmath>
using namespace std;
void swap(int &A, int &B){
    int temp = A;
    A = B;
    B = temp;
}

bool gcd_is_one(int m, int n){
    
    if(m<n) swap(m,n);
    
    while(m!=n){
        m = m-n;
        if(m<n) swap(m,n);
    }
    if(m==1) return true;
    else return false;
}

int check_conditions(int x, int A, int B, int max){
    if(A%x==0){
        if(gcd_is_one(x,B)){
            if(x>max) max = x;
        }
    }
    return max;
}

int Solution(int A, int B) {
    int max = 1;
    if(A==B) return 1;
    if(A==1) return 1;
    if(A==2 && B<4) return 2;

    max = check_conditions(A,A,B,max);

    int i = 2;
    while(A!=1){
        if(A%i==0 && B%i==0){
            A = A/i;
            B = B/i;
            max = check_conditions(A,A,B,max);
            continue;
        }
        else{
            i++;
        }
    }

    for(int x=2;x<=sqrt(A);x++){
        max = check_conditions(x,A,B,max);
        max = check_conditions(A/x,A,B,max);
    }
    return max;
}

int main(){
    int A=3, B=3;
    cout<<Solution(A,B);
    return 0;
}