#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &value, vector<int> &weight, int capacity, int idx, vector<vector<int>> &memo){
    if(memo[idx][capacity]!=-1)
        return memo[idx][capacity];

    if(capacity==0)
        return 0; //no value can be added
    if(idx==0)
        return 0;// no value can be added

    //for every index we are making a recursive call and at every call either include current weight if possible or exclude it, take the best answer
    if(weight[idx-1]<=capacity){
        //include (add value) and exclude
        memo[idx][capacity] = max(knapsack(value, weight, capacity, idx-1, memo), value[idx-1] + knapsack(value, weight, capacity-weight[idx-1], idx-1, memo));
        return memo[idx][capacity];
    }
    else{
        //just exclude
        memo[idx][capacity] = knapsack(value, weight, capacity, idx-1, memo);
        return memo[idx][capacity];
    }
}

int main(){
    vector<int> value = {10,40,30,50};
    vector<int> weight = {5,4,6,2};
    int capacity = 10;
    vector<vector<int>> memo(value.size()+1, vector<int>(capacity+1,-1));
    cout<<knapsack(value, weight, capacity, value.size(), memo);


    return 0;
}