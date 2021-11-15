//2D grid
//start at top left and goal is bottom right
//can only move down or right
//find total number of ways to reach the goal

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double gridTraveler(int row, int col,vector<vector<double>> &memo){
    //check if in memo
    // also memo(n,m) = memo(m,n)
    if(memo[row][col]!=-1)
        return memo[row][col];
    else if(memo[col][row]!=-1)
        return memo[col][row];

    if(row==1 and col==1){
        return 1;
    } 
    if(row==0 or col==0){
        return 0;
    }
    // going down means reducing row
    // going right means reducing col
    memo[row][col] = gridTraveler(row-1,col,memo) + gridTraveler(row,col-1,memo);
    return memo[row][col];
}

int main(){
    int n=18,m=18;
    vector<vector<double>> memo(n+1,vector<double>(m+1,-1)); // padding to keep 1 based indexing
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<memo[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"ans = "<<gridTraveler(n,m,memo)<<endl;
    // n=2,m=3;
    // memo.clear();
    // memo.resize(n,vector<int>(m,-1));
    // cout<<gridTraveler(n,m,memo)<<endl;
    // n=2,m=3;
    // memo.clear();
    // memo.resize(n,vector<int>(m,-1));
    // cout<<gridTraveler(n,m,memo)<<endl;
    // n=2,m=3;
    // memo.clear();
    // memo.resize(n,vector<int>(m,-1));
    // cout<<gridTraveler(n,m,memo)<<endl;
    return 0;
}