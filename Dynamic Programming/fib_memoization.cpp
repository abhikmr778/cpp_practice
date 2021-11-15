#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//memoization
 
int fib(int n, unordered_map<int,int> &mp){
    if(mp.count(n)){
        return mp[n];
    }
    if(n<=2){
        return 1;
    }

    mp[n] = fib(n-1,mp) + fib(n-2,mp);
    return mp[n];
}

int main(){
    unordered_map<int,int> mp;
    cout<<fib(6,mp)<<endl;
    cout<<fib(7,mp)<<endl;
    cout<<fib(30,mp)<<endl;
    // cout<<fib(12);
    return 0;
}