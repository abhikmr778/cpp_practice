#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// maximum value so that sum of weights of elements is less than knapsack capacity
// 
//example:
// values = [60,100,120]
// weights = [10,20,30]
// capacity = 50
// output: 220 ie take 20 and 30 weights with values 100 and 120
//
// base cases:
// if capacity = 0 output 0 ie can take nothing
// if capacity < weight of some element then skip this element
// alternatively if capacity<0 then return -1

int knapsack(vector<int> &values, vector<int> &weights, int len, int knapsackCapacity, vector<vector<int>> &memo){
    if(memo[len][knapsackCapacity]!=-1)
        return memo[len][knapsackCapacity];
    
    if(knapsackCapacity == 0 || len ==0)
        return 0;
    
    // try two things ie include ith element and exclude it
    
    int remainderCapacity = knapsackCapacity - weights[len-1];
    int newLength = len - 1;
    
    if(remainderCapacity>=0){
        int includeResult = values[len-1] + knapsack(values, weights, newLength, remainderCapacity, memo);
        
        int excludeResult = knapsack(values, weights, newLength, knapsackCapacity, memo);

        memo[len][knapsackCapacity] = max(includeResult, excludeResult);
        return max(includeResult, excludeResult);
    }
    else{
        int excludeResult = knapsack(values, weights, newLength, knapsackCapacity, memo);
        memo[len][knapsackCapacity] = excludeResult;
        return excludeResult;
    }
    
    memo[len][knapsackCapacity] = -1;
    return -1;
}


int main(){

    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20 , 30};
    int capacity = 50;
    vector<vector<int>> memo(values.size()+1, vector<int>(capacity+1, -1));
    cout<<knapsack(values, weights, values.size(), capacity, memo);



    return 0;
}