// #include <iostream>
#include <bits/stdc++.h>
# include<vector>
using namespace std;
int MOD = 1000003;
long long lessThanOnRHS(string A, int idx){
    long long count = 0;
    for(int i=idx+1;i<A.size();i++){
        if(A[i]<A[idx]){
            count ++;
        }
    }
    return count%MOD;
}
vector<int> count_freq(string A, int idx){
    vector<int> freq(52,0);
    for(int i=idx;i<A.size();i++){
        if(int(A[i])<='Z'){
            freq[int(A[i])-'A']++;
        }
        else{
            freq[int(A[i])-'a'+26]++;
        }
    }
    return freq;
}

long long compute_fact(long long n){
    long long ans = 1;
    while(n>1){
        ans = (ans*n)%MOD;
        // ans = ans%MOD;
        n--;
    }
    return ans%MOD;
}

long long compute_rep_fact(vector<int> V){
    long long prod = 1;
    for(int i=0;i<V.size();i++){
        if(V[i]>1){
            prod = prod*compute_fact(V[i]);
            // prod = prod;
        }
    }
    return prod%MOD;
}

int findRank(string A){
    long long t_count = 1;
    long long n = A.size();
    for(int i=0;i<n;i++){
        long long less_than = lessThanOnRHS(A,i);
        vector<int> d_count = count_freq(A,i);
        long long d_fac = compute_rep_fact(d_count);
        t_count += (less_than*compute_fact(n-i-1))/d_fac;
        // t_count = t_count%MOD;
    }
    return t_count%MOD;
}
int main(){
    string s="asasdsdsadasdadsadasdsa";
    // cout<<int('z')-int('A')<<endl<<int('A')<<endl;
    cout<<findRank(s);
    return 0;
}