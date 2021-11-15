#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// base cases
// g(egg=1,floor=f) = f
// g(e,1) = 1
// g(e,0) = 0


int minDrops(int e, int f){ // e = eggs, f =max floor
    int dp[f+1][e+1];
    //base cases
    for(int i=0; i<=f; i++)
        dp[i][1] = i;
    
    for(int j=0; j<=e; j++){
        dp[0][j] = 0;
        dp[1][j] = 1;
    }

    for(int i=2; i<=f; i++){
        for(int j=1; j<=e; j++){
            dp[i][j] = INT_MAX;
            for(int x=1; x<=i; x++){
                dp[i][j] = min(
                    dp[i][j],
                    1+max(dp[i-1][j-1], dp[i-x][j])
                );
            }
        }
    }
    return dp[f][e];
    
}

int main(){
    int e=2, f=10;
    cout<<minDrops(e,f);

    return 0;
}