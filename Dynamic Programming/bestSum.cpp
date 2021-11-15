#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> bestSum(int target, vector<int> &nums, unordered_map<int, vector<int>> &memo){
    // memo base case
    if(memo.count(target)){
        return memo[target];
    }

    if(target==0)
        return {};
    if(target<0)
        return {-1};

    vector<int> bestans = {-1};

    for(int i=0; i<nums.size(); i++){
        int remainder = target - nums[i];
        vector<int> remainderCombination = bestSum(remainder, nums, memo);
        //if this remainderCombination is not {-1} then do logic
        if(remainderCombination.empty() or remainderCombination[0]!=-1){
            
            remainderCombination.push_back(nums[i]);

            //if bestans is null or we have found a better answer then update it
            if(bestans[0]==-1 or remainderCombination.size()<bestans.size()){
                bestans = remainderCombination;
            }
        }
    }

    memo[target] = bestans;
    return bestans; //will be {-1} if we dont get any answer in above for loop
}


// m = target sum, n = nums.size()
//
// Brute force:
// time: O(n^m) for every target m we could branch out into n children at worst case
// space: O(m) recursion stack + O(m) for every recursive call ==> O(m*m) space
//          ie in the worst case we will have m recursion calls in the stack and each of the calls
//          will have m length vector to store the bestans therefore 
//          space: O(m*m)
//
// Memoization:
// time: O(n*m) ie for every target we branch out to n children but we memoize them so we do this only once
// space: O(m*m) for each recursive call having size m vector + O(m*m) memo space ie for every key we can have m length vector

int main(){

    int target = 100;
    vector<int> nums = {1,2,5,25};
    unordered_map<int, vector<int>> memo;
    vector<int> ans = bestSum(target, nums, memo);
    //add memoization
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}