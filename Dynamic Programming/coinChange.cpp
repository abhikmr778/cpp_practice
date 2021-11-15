#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// count distinct ways!
// infinite supply of coins
int countWays(int target, vector<int> coins, int n, unordered_map<int, int> &memo){
    //memo base case
    if(memo.count(target))
        return memo[target];

    // base cases
    if(n==0)
        return 0;
    if(target == 0)
        return 1; // then there's only one way ie do nothing

    
    int res = countWays(target, coins, n-1, memo); // ignore this coin
    if(coins[n-1]<=target){// include this coin if it can be included
        res += countWays(target - coins[n-1], coins, n, memo);
    }    
    memo[target] = res;
    return res;
}

int main(){

    int target = 10;
    vector<int> coins = {2,5,3,6};
    unordered_map<int, int> memo;
    cout<<countWays(target, coins, coins.size(), memo)<<endl;
    return 0;
}