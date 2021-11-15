#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int LISlength(vector<int> arr){
    int lis[arr.size()];
    // base case
    lis[0] = 1; //1 element

    //for every element travers through the elements before it to update current LIS value
    for(int i=1; i<arr.size(); i++){
        lis[i] = 1; //initially
        for(int j=0; j<i; j++){
            //so if any element before i is smaller than ith, then it can be a part of LIS of length i
            if(arr[j]<arr[i])
                lis[i] = max(lis[i], lis[j]+1);
        }
    }
    int res = 0;
    for(int item: lis)
        res = max(res, item);

    return res;
}

int main(){

    vector<int> arr = {3,4,2,8,10};
    cout<<LISlength(arr)<<endl;

    return 0;
}