#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// bool howSum(int target, vector<int> &nums, vector<int> &ans){
//     if(target==0)
//         return true;
//     if(target<0)
//         return false;

//     for(int i=0; i<nums.size(); i++){
//         if(howSum(target-nums[i],nums,ans)){
//             ans.push_back(nums[i]);
//             return true;
//         }
//     }
//     //otherwise backtrack popback
//     ans.pop_back();
//     return false;
// }

vector<int> howSum(int target, vector<int> &nums, unordered_map<int, vector<int>> &memo){
    //memo base case
    if(memo.count(target)){
        return memo[target];
    }
    
    if(target==0)
        return {};
    if(target<0)
        return {-1};

    for(int i=0; i<nums.size(); i++){

        int remainder = target - nums[i];

        vector<int> remainderResult = howSum(remainder, nums, memo);
        
        if(remainderResult.empty() or remainderResult[0]!=-1){
            remainderResult.push_back(nums[i]); // push back only when result is possible ie avoid {-1}
            memo[target] = remainderResult;
            return remainderResult;
        }

    }
    memo[target] = {-1};
    return {-1};
}

// m = target sum, n = nums.size()
//
//Brute Force: Overlapping subproblems
// time: O(n^m) ie every node at worst case can be branched into m children
// aux space: O(m) 
//
//Memoized
// time: O(m*n) recursive calls in worst case
// space: O(m) for stack + O(m*m) for memo in worst case
int main(){
    int target = 300;
    vector<int> nums = {14,10};
    //memoize
    unordered_map<int, vector<int>> memo; //contains vector soln corresponding to every target 
    vector<int> ans = howSum(target, nums, memo);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    return 0;
}