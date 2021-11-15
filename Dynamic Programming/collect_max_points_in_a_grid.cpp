#include <bits/stdc++.h>

using namespace std;

#define N 100
int n, m;
int a[N][N];

vector<vector<int>> dp(N, vector<int>(N)), visited(N, vector<int>(N));

int current_sum = 0;

int total_sum = 0;

void inputMatrix(){
    n = 3;
    m = 3;
    a[0][0] = 500;
    a[0][1] = 100;
    a[0][2] = 230;
    a[1][0] = 1000;
    a[1][1] = 300;
    a[1][2] = 100;
    a[2][0] = 200;
    a[2][1] = 1000;
    a[2][2] = 200;
}

int maximum_sum_path(int i, int j){
    if(i==n-1 && j==m-1){
        return a[i][j];
    }

    if(visited[i][j])
        return dp[i][j];
    
    visited[i][j] = 1;

    int &total_sum = dp[i][j];

    if(i<n-1 && j<m-1){
        int current_sum = max(maximum_sum_path(i,j+1),maximum_sum_path(i+1,j));
        total_sum = a[i][j] + current_sum;
    }
    else if(i==n-1){
        total_sum = a[i][j] + maximum_sum_path(i, j+1);
    }
    else{
        total_sum = a[i][j] + maximum_sum_path(i+1,j);
    }

    return dp[i][j] = total_sum;
}


int main(){
  
    inputMatrix();
 
    // Calling the implemented function
    int maximum_sum = maximum_sum_path(0, 0);
 
    cout << maximum_sum;
    return 0;
}