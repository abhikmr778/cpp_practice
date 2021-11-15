#include <iostream>
#include <cmath>
using namespace std;

void swap(int &A, int &B){
    int temp = A;
    A = B;
    B = temp;
}

int gcd_(int m, int n){
    
    if(m<n) swap(m,n);
    
    while(m!=n){
        m = m-n;
        if(m<n) swap(m,n);
    }
    return m;
}

int Solution(int A, int B){
    // int max = 1;
    // if(A==B) return 1;
    // if(A==1) return 1;
    // if(A==2 && B<4) return 2;

    int gcd = gcd_(A,B);
    while(gcd!=1){
        A = A/gcd;
        gcd = gcd_(A,B);
        cout<<A<<","<<B<<endl;
    }

    return A;
}

int main(){
    int A=24, B=36;
    cout<<Solution(A,B);
    return 0;
}