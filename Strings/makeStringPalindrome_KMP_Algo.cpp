#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string C){
    int M = C.length();
    vector<int> lps(M);

    int len=0;
    lps[0] = 0;

    int i=1;
    while(i<M){
        if(C[i]==C[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

int minReqChar(string A){
    string revA = A;
    reverse(revA.begin(),revA.end());

    string concat = A+'$'+revA;

    vector<int> lps = computeLPS(concat);

    return A.length()-lps.back();
}


int main(){

    string A = "aacecaaaa";
    cout<<minReqChar(A);


    return 0;
}