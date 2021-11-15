#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findCeil(int arr[], int left, int right, int key){
    while(left<right){
        int mid = left + (right-left)/2;
        if(arr[mid]<key){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    //ceil will always exist so just return 'right' 
    return right;
}

int LISlength(vector<int> arr){
    int n = arr.size();
    int tail[n];
    // tail[i] represents the smallest ending element for LIS in arr[0...i]
    //base case
    // for single element tail will be element itself
    int tail_idx = 0;
    tail[tail_idx] = arr[0];
    
    //traverse through all other elements
    //if element is smaller than last tail value then find its correct position by finding ceil of this curr element
    // we are trying to make LIS of all lengths using smallest values given arr of length i
    for(int i=1; i<n; i++){
        if(arr[i]<tail[tail_idx]){
            int idx_to_place_current_value = findCeil(tail,0,tail_idx,arr[i]);
            tail[idx_to_place_current_value] = arr[i];
        }else{
            tail[++tail_idx] = arr[i];
        }
    }
    return tail_idx+1; //length of tail is answer
}

int main(){

    vector<int> arr = {8,100,150,10,12,14,110};
    cout<<LISlength(arr)<<endl;
    return 0;
}