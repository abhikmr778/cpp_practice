#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // can use dp to build up solution
    
    //base case ie length should at least be 3
    if(A.size()<=2)
        return 0;
    if(A.size()==3){
        return A[2]-A[1]==A[1]-A[0];
    }
    
    int sub_result = 0;
    int result = 0;
    unsigned i=2;

    while(i<A.size()){
        if(A[i]-A[i-1]==A[i-1]-A[i-2]){
            sub_result++;
        }
        else{
            sub_result = 0;
        }
        result += sub_result;
        i++;
    }

    return result;

}

int main(){
    vector<int> A = {-1000000000, 0, 1000000000, 1000000000, 1000000000, 1000000000};

    cout<<solution(A);
    return 0;
}