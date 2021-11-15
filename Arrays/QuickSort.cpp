#include <iostream>
using namespace std;

void swap(int *i,int *index){
    int temp = *i;
    *i = *index;
    *index = temp;
}

int partition(int *arr,int low, int high){
    int index = low;
    int pivot = high;
    for(int i=low;i<high;i++){
        if(arr[i]<arr[pivot]){
            swap(&arr[i],&arr[index]);
            index++;
        }
    }
    swap(&arr[pivot],&arr[index]);
    return index;
}

void quickSort(int *arr,int low, int high){
    if(low<high){
        int pivot_idx = partition(arr,low,high);
        quickSort(arr,low,pivot_idx-1);
        quickSort(arr,pivot_idx+1,high);
    }
    else{
        return;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for (int j = 0; j < n; j++)
    {
        cout<<arr[j]<<" ";
    }
    
    return 0;
}