#include <bits/stdc++.h>

using namespace std;
bool mycomp(pair<int, int> a, pair<int, int> b){
    if(a.first!=b.first)
        return a.first<b.first;
    else return a.second<b.second;
}

int insert_index(vector<int> heights, int curr_h){
    int l = 0;
    int r = heights.size()-1;
    int res = 0;
    while(l<=r){
        int mid = l + (r-l)/2;
        int h = heights[mid];
        if(h<curr_h){
            res = mid;
            l = mid+1;
        } 
        else{
            r = mid-1;
        }
    }
    return res+1;
}

void solve(vector<pair<int, int>> boxes){
    sort(boxes.begin(), boxes.end(), mycomp);
    int n = boxes.size();
    vector<int> heights(n+1, INT_MAX);
    heights[0] = INT_MIN;
    int res = 0;

    for(auto box: boxes){
        int curr_w = box.first;
        int curr_h = box.second;
        int idx = insert_index(heights, curr_h);

        if(heights[idx]>=curr_h){
            heights[idx] = curr_h;
        }
        res = max(res, idx);
    }
    cout<<res;
}

int main(){

    vector<pair<int, int>> boxes = {
        {12,12},
        {10,10},
        {6,6},
        {5,10}
    };

    solve(boxes);

    return 0;
}