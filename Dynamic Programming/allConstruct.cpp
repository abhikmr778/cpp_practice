#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> allConstruct(string target, vector<string> &wordBank, unordered_map<string, vector<vector<string>>> &memo){
    if(memo.count(target))
        return memo[target];
    
    if(target=="")
        return {{}}; // solution exists
    
    
    vector<vector<string>> ans = {};

    for(int i=0; i<wordBank.size(); i++){
        if(target.compare(0,wordBank[i].length(), wordBank[i])==0){
            
            string suffix = target.substr(wordBank[i].length(),target.length()-wordBank[i].length());
            
            vector<vector<string>> suffixWays = allConstruct(suffix, wordBank, memo);

            // copy the current word in front of all the solutions for suffix
            for(int j=0; j<suffixWays.size(); j++){
                suffixWays[j].insert(suffixWays[j].begin(), wordBank[i]);
            }

            //copy all answers to return
            for(auto item: suffixWays)
                ans.push_back(item);

        }
    }
    memo[target] = ans;
    return ans;


}

int main(){

    string target = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<string> wordBank = {"aaaaa", "aaaaaaaaa", "aaaaaaaaaa", "aaaaaaaaaaaaaaaaaaa"};
    unordered_map<string, vector<vector<string>>> memo;
    vector<vector<string>> res = allConstruct(target, wordBank, memo);
    for(auto item: res){
        for(auto st: item)
            cout<<st<<" ";
        cout<<endl;
    }

    return 0;
}