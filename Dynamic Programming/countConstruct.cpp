#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int countConstruct(string target, vector<string> &wordBank, unordered_map<string, double> &memo){
    if(memo.count(target))
        return memo[target];

    if(target=="")
        return 1;

    double totalCount = 0;
    for(int i=0; i<wordBank.size(); i++){
        if(target.compare(0,wordBank[i].length(), wordBank[i])==0){
            string suffix = target.substr(wordBank[i].length(), target.length()-wordBank[i].length());
            totalCount += countConstruct(suffix, wordBank, memo);
        }
    }
    memo[target] = totalCount;
    return totalCount;
}
 

int main(){

    string target = "eeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string> wordBank = {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeeeee", "eeeeeeeeef"};
    unordered_map<string, double> memo;
    cout<<countConstruct(target, wordBank, memo)<<endl;

    return 0;
}