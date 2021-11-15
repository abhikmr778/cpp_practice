#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> minCoins(int target, vector<int> coins, unordered_map<int, vector<int>> memo){
    if(memo.count(target))
        return memo[target];

    if(target == 0)
        return {};
    
    //res variable to store min ans for this stack call
    vector<int> ans = {-1};
    //traverse through all coins that can be subtracted from the target
    for(int i=0; i<coins.size(); i++){
        int remainder = target - coins[i];
        if(remainder>=0){
            vector<int> remainderResult = minCoins(remainder,coins, memo); //add 1 cuz adding a coin
            if(remainderResult.empty() || remainderResult[0]!=-1){
                remainderResult.push_back(coins[i]);

                if(ans[0]==-1) // handle first time update
                    ans = remainderResult;
                else{
                    if(remainderResult.size()<ans.size())
                        ans = remainderResult;
                }
            }
        }
    }
    memo[target] = ans;
    return ans;
}

int main(){
    vector<int> coins = {25,10,5,15};
    int target = 40;
    unordered_map<int, vector<int>> memo;
    vector<int> ans = minCoins(target, coins, memo);
    for(int item: ans)
        cout<<item<<" ";
    return 0;
}