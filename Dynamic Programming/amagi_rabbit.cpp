#include <bits/stdc++.h>

using namespace std;

int max_sum_path(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp){
    int R = grid.size();
    int C = grid[0].size();

    // base case
    if(row == R-1 && col == C-1)
        return grid[row][col];
    if(dp[row][col]!=-1)
        return dp[row][col];
    int total_sum = 0;
    // if not at last row or col then we can go down or right
    if(row<R-1 && col<C-1){
        int curr_sum = max(max_sum_path(grid, row+1, col, dp), max_sum_path(grid, row, col+1, dp));
        total_sum = grid[row][col] + curr_sum;    
    }
    else if(row==R-1){
        total_sum = grid[row][col] + max_sum_path(grid, row, col+1, dp);
    }
    else{
        total_sum = grid[row][col] + max_sum_path(grid, row+1, col, dp);
    }
    return dp[row][col] = total_sum;
}

int main(){

    vector<vector<int>> grid = {{100, -350, -200},
           {-100, -300, 700}};
    int R = grid.size();
    int C = grid[0].size();
    vector<vector<int>> dp(R, vector<int>(C,-1));
    int res = max_sum_path(grid, 0, 0, dp);
    cout<<res<<endl;
    return 0;
}