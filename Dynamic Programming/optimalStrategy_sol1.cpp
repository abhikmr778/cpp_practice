#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> arr, int left, int right, int sum){
    if(right == left+1)
        return max(arr[left], arr[right]);

    return max(
                sum - solve(arr,left+1,right,sum-arr[left]),
                sum - solve(arr,left,right-1,sum-arr[right])
    );

}

int main(){

    vector<int> arr = {20,5,4,6};
    int sum = 0;
    for(int x: arr)
        sum += x;
    cout<<solve(arr,0,arr.size()-1,sum);

    return 0;
}