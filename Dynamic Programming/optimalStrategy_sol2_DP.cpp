#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> arr, int start, int end, vector<vector<int>> &memo){
    if(memo[start][end]!=-1)
        return memo[start][end];

    if(end == start+1){
        memo[start][end] = max(arr[start], arr[end]);
        return memo[start][end];
    }

    // we have two choices we need to maximize and oponent will play two choices that we have to minimize
    memo[start][end] = max(
        arr[start] + min(solve(arr,start+1,end-1, memo), solve(arr, start+2, end, memo)), //our choice + min(whatever choice oponent has now)
        arr[end] + min(solve(arr, start+1, end-1, memo), solve(arr, start, end-2, memo))
    );
    return memo[start][end];

}


int main(){

    vector<int> arr = {20,5,4,6};
    vector<vector<int>> memo(arr.size(), vector<int>(arr.size(),-1));
    cout<<solve(arr, 0, arr.size()-1, memo);


    return 0;
}