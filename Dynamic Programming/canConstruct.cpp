#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool canConstruct(string target, vector<string> &wordbank, unordered_map<string, bool> &memo){
    if(memo.count(target))
        return memo[target];
    
    if(target=="")
        return true;
    
    for(int i=0; i<wordbank.size(); i++){
        //need to check if word in wordbank is a prefix to the target
        if(target.compare(0,wordbank[i].length(),wordbank[i])==0){
            string suffix = target.substr(wordbank[i].length(), target.length()-wordbank[i].length());
            if(canConstruct(suffix, wordbank, memo)==true){
                memo[target] = true;
                return true;
            }
        }
    }
    memo[target] = false;
    return false;
}

int main(){

    string target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string> wordbank = {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeeeee", "eeeeeeeee"};
    unordered_map<string, bool> memo;
    cout<<canConstruct(target, wordbank, memo)<<endl;

    return 0;
}