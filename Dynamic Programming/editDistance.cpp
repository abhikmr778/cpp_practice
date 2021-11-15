#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int editDistance(string s1, string s2, int len1, int len2, vector<vector<int>> &memo){
    // base cases
    if(memo[len1][len2]!=-1)
        return memo[len1][len2];
    // both zero
    if(len1==0 && len2==0)
        return 0;
    
    if(len1==0)
        return len2;
    if(len2==0)
        return len1;

    //if matches then skip otherwise
    //delete from s1 and delete from s2 and also replace
    if(s1[len1-1]==s2[len2-1]){
        memo[len1][len2] = editDistance(s1,s2,len1-1,len2-1,memo);
        return memo[len1][len2];
    }
    else{
        int deletes1 = editDistance(s1,s2,len1-1,len2,memo);
        int deletes2 = editDistance(s1,s2,len1,len2-1,memo);
        int replace = editDistance(s1,s2,len1-1,len2-1,memo);
        memo[len1][len2] = 1+min(min(deletes1, deletes2), replace);
        return memo[len1][len2];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
    }

}

int main(){

    string s1 = "cart";
    string s2 = "cord";
    vector<vector<int>> memo(s1.length()+1, vector<int>(s2.length()+1,-1));
    cout<<editDistance(s1,s2,s1.length(),s2.length(), memo)<<endl;

    return 0;
}