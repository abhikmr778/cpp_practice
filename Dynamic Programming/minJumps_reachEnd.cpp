#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> minJumps(vector<int> jumps, int curr, int target, unordered_map<int, vector<int>> &memo){
    if(memo.count(curr))
        return memo[curr];

    if(curr==target)
        return {};

    vector<int> ans = {-1}; //update min jumps in this var
    //trvarse through all the jumps possible from curr element
    for(int i=1; i<=jumps[curr]; i++){
        //if making a jump is within target then make a jump
        int next_position = curr+i;
        
        if(next_position<=target){
            //making a jump so add one to result
            vector<int> next_posResult = minJumps(jumps, next_position, target, memo);
            if(next_posResult.empty() || next_posResult[0]!=-1){
                //handle first time update
                next_posResult.push_back(i);
                if(ans[0]==-1)
                    ans = next_posResult;
                else if(next_posResult.size()<ans.size()){
                    ans = next_posResult;
                }
            }
                
        }
    }
    memo[curr] = ans;
    return ans;
}

int main(){

    vector<int> jumps = {4,1,5,3,1,3,2,1,8};
    unordered_map<int, vector<int>> memo;
    vector<int> ans = minJumps(jumps,0,jumps.size()-1, memo);
    for(int item: ans)
        cout<<item<<" ";
    return 0;
}