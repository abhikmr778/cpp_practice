#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool canSum(int target, vector<int> nums, unordered_map<int,bool> &memo){
    //memo base case
    if(memo.count(target))
        return memo[target];
        
    if(target==0)
        return true;
    if(target<0) 
        return false;
    
    for(int i=0; i<nums.size(); i++){
        if(canSum(target-nums[i],nums, memo)==true){
            memo[target] = true;
            return true;
        }
    }
    // if none of the calls in for loop worked out then return false
    memo[target] = false;
    return false;
}

int main(){
    // int target = 7;
    // vector<int> nums = {2,3};
    // cout<<canSum(target,nums)<<endl;
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int target;
        int n;
        vector<int> nums;
        unordered_map<int,bool> memo;
        cin>>target;
        cin>>n;
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }

        if(canSum(target,nums,memo))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;

    }

    return 0;
}