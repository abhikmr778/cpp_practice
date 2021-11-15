#include <iostream>
using namespace std;

void merge(int *A, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int temp[end-start+1], k=0;
    while(i<=mid && j<=end){
        if(A[i]<=A[j]){
            temp[k] = A[i];
            k++, i++;
        }
        else{
            temp [k] = A[j];
            k++, j++;
        }
    }

    while(i<=mid){
        temp[k] = A[i];
        k++,i++;
    }

    while(j<=end){
        temp[k] = A[j];
        k++,j++;
    }

    for(int l=start;l<=end;l++){
        A[l] = temp[l-start]; 
    }
}


void mergeSort(int *A, int start, int end){
    if(start<end){
        int mid = (start + end)/2;
        mergeSort(A,start,mid);
        mergeSort(A,mid+1,end);
        merge(A,start,mid,end); 
    }
}

int main(){
    int n=8;
    // cin>>n;
    int A[] = {14,7,3,12,9,11,6,2};
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;
    mergeSort(A,0,n-1);
    // cout<<"l3";
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    return 0;
}