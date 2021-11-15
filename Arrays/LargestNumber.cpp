// Given a list of non negative integers, arrange them such that they form the largest number.

// For example:

// Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int myCompare(string a, string b){
    string ab = a.append(b);
    string ba = b.append(a);
    return ab.compare(ba)>0 ? 1 : 0;
}

string largestNumber(const vector<int> &A){
    //make a vector of string to store numbers as strings
    vector<string> str;
    
    //push all values by converting to string
    for(int i=0;i<A.size();i++){
        str.push_back(to_string(A[i]));
    }
    
    //now sort by using a custom comparison method
    sort(str.begin(),str.end(),myCompare);

    string ans = "";
    for(int i=0;i<str.size();i++){
        ans += str[i];
    }
    int t = 0;
    while(ans[t]=='0'){
        t++;
    }

    if(t==ans.length()){
        ans = "0";
    }
    return ans;

}


int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    string s;
    s = largestNumber(A);
    cout<<s;
    return 0;
}