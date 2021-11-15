#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr,int n){
    int unsorted_idx = 0, sorted_idx = 0;
    for(int i=unsorted_idx;i<n;i++){
        int min = INT32_MAX;
        int min_idx;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                min_idx = j;
            } 
        }
        swap(arr[min_idx],arr[i]);
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
}