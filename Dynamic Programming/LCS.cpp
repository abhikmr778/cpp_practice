#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int countLCS(string s1, int len1, string s2, int len2, vector<vector<int>> &memo){
    // memo base case
    if(memo[len1][len2]!=-1)
        return memo[len1][len2];

    // base cases
    if(len1 == 0 || len2 == 0){
        return 0;
    }

    // if matches reduce both and add 1 to answer
    if(s1[len1-1] == s2[len2-1]){
        memo[len1][len2] = countLCS(s1, len1-1, s2, len2-1, memo) + 1;
        return memo[len1][len2];

    }

    // else return max of both 
    int reduce_s1 = countLCS(s1, len1-1, s2, len2, memo);
    int reduce_s2 = countLCS(s1, len1, s2, len2-1, memo);

    int res = max(reduce_s1, reduce_s2);
    memo[len1][len2] = res;
    return res;
    
}

int main(){

    string s1 = "abcdgh";
    string s2 = "aedfhr";
    vector<vector<int>> memo(s1.length()+1, vector<int>(s2.length()+1, -1));
    cout<<countLCS(s1, s1.length(), s2, s2.length(), memo)<<endl;
    return 0;
}