#include <bits/stdc++.h>
// #include <iostream>
using namespace std;
int binarySearch(int *arr, int toFind, int n){
    int low = 0;
    int high = n-1;
    int mid;
    while(low<=high){
        mid = low+(high-low)/2;
        if(arr[mid]==toFind) return mid;
        else if(arr[mid]<toFind) low = mid+1;
        else if(arr[mid]>toFind) high = mid-1;
    }
    return -1;
}

int main(){
    int n = 8;
    int arr[] = {1,2,3,4,5,6,7,8};
    int toFind = 9;
    int idx;
    idx = binarySearch(arr,toFind,n);
    if(idx!=-1){
        cout<<"Yes, the element "<<toFind<<" exists at index "<<idx<<" in the array.";
    }
    else{
        cout<<"Element does not exist.";
    }
    return 0;
}