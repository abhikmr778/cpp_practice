#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxCuts(int target, vector<int> cuts, unordered_map<int,int> &memo){
    if(memo.count(target))
        return memo[target];
    //base cases
    if(target==0) //successfully cut
        return 0;
    
    int ans = -1;
    //branch out into m cuts
    for(int i=0; i<cuts.size(); i++){
        int remainder = target - cuts[i];
        if(remainder>=0){
            int remainderAns = 1+maxCuts(remainder, cuts, memo); //add 1 because we are making a cut
            if(remainderAns!=-1){
                ans = max(ans,remainderAns);
            }
        }
    }
    memo[target] = ans;
    return ans;
}

int main(){

    vector<int> cuts = {1,2,5};
    int target = 20;
    unordered_map<int, int> memo;
    cout<<maxCuts(target, cuts, memo);
    return 0;
}