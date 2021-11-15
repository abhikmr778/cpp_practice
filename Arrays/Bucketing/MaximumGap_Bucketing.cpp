// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    int maxVal = *max_element(nums.begin(),nums.end());
    cout<<"max: "<<maxVal<<endl;
    int minVal = *min_element(nums.begin(),nums.end());
    cout<<"min: "<<minVal<<endl;

    int bucket_size = ceil(float(maxVal-minVal)/float(n-1.0));
    cout<<"bucket size: "<<bucket_size<<endl;

    vector<int> bucket_max(n-1,INT32_MIN);
    vector<int> bucket_min(n-1,INT32_MAX);

    for(int j=0;j<n;j++){
        if(nums[j]==minVal || nums[j]==maxVal) continue;
        
        int bucket_index = (nums[j]-minVal)/bucket_size;

        bucket_max[bucket_index] = max(bucket_max[bucket_index],nums[j]);
        bucket_min[bucket_index] = min(bucket_min[bucket_index],nums[j]);

    }
    int maxGap = 0;
    int prevMax = minVal;
    for(int k=0;k<n-1;k++){
        if(bucket_min[k]==INT32_MAX) continue;
        maxGap = max(maxGap,bucket_min[k]-minVal);
        minVal = bucket_max[k];
    }
    maxGap = max(maxGap,maxVal-minVal); //// to check max of last bucket with the maximum value of array
    cout<<maxGap;
    return 0;
}